#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"


template <typename D>   
ListD<D>::ListD()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode<D>;
 tail = new doubleNode<D>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = -1;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = -10;
 tail->next = NULL;
}

template <typename D>   
ListD<D>::ListD(ListD* lst)
{
 length = 0; 
 
//create dummy nodes;
 head = new doubleNode<D>;
 tail = new doubleNode<D>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = -1;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = -10;
 tail->next = NULL;

 //returns pointer to the first node, which is what we want here
 doubleNode<D>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

template <typename D>   
ListD<D>::~ListD()
{
 while (head->next != tail)
 {
  doubleNode<D>* temp = head->next;
  temp->next->prev = head;
  head->next = temp->next;
  delete temp;
  length--;
 }
 delete head;
 delete tail;
 
}

template <typename D>
doubleNode<D>* ListD<D>::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode<D>* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 

template <typename D> 
void ListD<D>::Insert(D item, int pos)
{
 //new node goes between these two nodes
 doubleNode<D>* insertPtA = FindPosition(pos);  
 doubleNode<D>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<D>* tmp = new doubleNode<D>; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template <typename D> 
void ListD<D>::PrintForward()
{
 doubleNode<D>* cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

template <typename D> 
void ListD<D>::PrintBackward()
{
 doubleNode<D>* cur = tail->prev;
 
 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->prev;
  i++;
 } 
}



template <typename D>   
void ListD<D>::Delete(int pos)
{
 doubleNode<D>* temp = FindPosition(pos+1);
 temp->prev->next = temp->next;
 temp->next->prev = temp->prev;
 length--;
 
 delete temp;
}

template <typename D>   
int ListD<D>::DeleteAll(D item)
{
 doubleNode<D>* cur = head;
 doubleNode<D>* temp = head;
 int ct = 0;
 
 while (cur->next != tail)
 {
  temp = cur;
  cur = cur->next;
  if (cur->item == item)
  {
   temp->next = cur->next;
   cur->next->prev = temp;
   ct++;
   length--;
  }
 }
 
 return ct;
}

template <typename D>   
void ListD<D>::Sort()
{
  doubleNode<D>* temp = head;
  doubleNode<D>* min;
  doubleNode<D>* nxt;
  int i = 1;
    
    while (i < length) {
        temp = temp->next;
        min = temp;
        nxt = temp->next;
        
        while (nxt->item != tail->item) {
            if (min->item > nxt->item)
                min = nxt;
  
            nxt = nxt->next;
        }
        i++;
        
        int x = temp->item;
        temp->item = min->item;
        min->item = x;
    }
}


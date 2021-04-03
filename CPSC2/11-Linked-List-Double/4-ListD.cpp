#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

   
ListD::ListD()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

ListD::ListD(ListD* lst)
{
 length = 0; 
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;

 //returns pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

ListD::~ListD()
{
 while (head->next != tail)
 {
  doubleNode* temp = head->next;
  temp->next->prev = head;
  head->next = temp->next;
  delete temp;
  length--;
 }
 delete head;
 delete tail;
 
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode* cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

void ListD::PrintBackward()
{
 doubleNode* cur = tail->prev;
 
 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->prev;
  i++;
 } 
}

void ListD::Delete(int pos)
{
 doubleNode* temp = FindPosition(pos+1);
 temp->prev->next = temp->next;
 temp->next->prev = temp->prev;
 length--;
 
 delete temp;
}

int ListD::DeleteAll(itemType item)
{
 doubleNode* cur = head;
 doubleNode* temp = head;
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

void ListD::Sort()
{
  doubleNode* temp = head;
  doubleNode* min;
  doubleNode* nxt;
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

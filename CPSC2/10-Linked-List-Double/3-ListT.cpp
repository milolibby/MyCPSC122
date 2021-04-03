#include <iostream>
using namespace std;

#include "3-ListT.h"

ListT::ListT()
{
 head = NULL;
 tail = NULL; 
 length = 0;
}

ListT::~ListT()
{
 node* temp = head;
 while (head != NULL)
 {
  temp = head->next;
  delete head;
  head = temp;
 }
}

bool ListT::IsEmpty() const
{
 if (length == 0)
  return true;

 return false;
}

int ListT::GetLength() const
{
 return length;
}

void ListT::PutItemH(const itemType itemIn)
{
 node* tmp = new node; 
 tmp->item = itemIn;
 tmp->next = head;
 
 if (head == NULL)
 {
  head = tmp;
  tail = tmp;
 }
 else
 {
  head = tmp;
 }
 length++;
}

void ListT::Print() const
{
 node* cur = head;
 cout << "Current List:" << endl;
 while (cur != NULL && length > 0)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
 cout << endl;
}


itemType ListT::GetItemH() const
{
 return head->item;
}


void ListT::DeleteItemH()
{

 node* del = head;
 head = head->next;
 cout << "Deleting: " << del->item << endl;
 length--;
 delete del;
}

void ListT::PutItemT(const itemType itemIn)
{
 node* tmp = new node;
 tmp->item = itemIn;
 tmp->next = NULL;
 
 if (head == NULL)
 {
  head = tmp;
  tail = tmp;
 }
 else
 {
  tail->next = tmp;
  tail = tmp;
 }
 length++;
}
	
itemType ListT::GetItemT() const
{
 return tail->item;
}

void ListT::DeleteItemT()
{
 node* del = tail;
/*
 //Test of PtrTo
 cout << "Test of PtrTo" << endl;
 cout << "********************" << endl;
 cout << tail->item << endl;
 cout << "Using PtrTo get address of node just before node tail is pointing to" << endl << endl;
 node* test = PtrTo();
 cout << "Address of node->next: " << test->next << endl;
 cout << "Address of tail: " << tail << endl << endl;
 cout << "If the two addresses are the same, test is passed" << endl << endl;
 if (test->next == tail)
  cout << "Addresses are the same, the next node from the one returned by PtrTo is indeed the tail" << endl << endl;
 //End of Test
*/
 tail = PtrTo();
 tail->next = NULL;
 cout << "Deleting: " << del->item << endl;
 length--;
 delete del;
}

node* ListT::PtrTo()
{
 node* cur = head;
 for (int i = 1; i < length - 1; i++)
  cur = cur->next;
 return cur;
}


int ListT::FindItem(const itemType target) const
{
 node* cur = head;
 int ct = 0;
 
 if (cur->item == target)
  ct++;
 for (int i = 1; i < length; i++)
 {
  cur = cur->next;
  if (cur->item == target)
   ct++;
 }
 return ct;
}


int ListT::DeleteItem(const itemType target)
{
 node* cur = head;
 node* prev = head;
 int ct = 0;
 
 if (head->item == target) //checks if head of list matches
 {
  head = head->next;
  ct++;
  length--;
 }
 
 for (int i = 1;i < length; i++)
 {
  if (target == head->item)
   head = head->next;
  prev = cur;
  cur = cur->next;
  if (cur->item == target)
  {
   if (target == tail->item)
    tail = prev;
   cur = prev->next;
   prev->next = cur->next;
   ct++;
   length--;
  }
 }
 
 return ct;
}




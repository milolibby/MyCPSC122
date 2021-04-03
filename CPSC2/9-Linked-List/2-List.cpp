#include <iostream>
using namespace std;

#include "2-List.h"

List::List()
{
 length = 0;
 head = new node;
 head = NULL;
}

List::~List()
{
 delete head;
}

bool List::IsEmpty() const
{
 if (length == 0)
  return true;

 return false;
}

int List::GetLength() const
{
 return length;
}

void List::PutItemH(const itemType newItem)
{
 node* tmp = new node; 
 tmp->item = newItem;
 tmp->next = head;
 head = tmp;
 length++;
}

itemType List::GetItemH() const
{
 return head->item;
}

void List::DeleteItemH()
{

 node* del = head;
 head = head->next;
 cout << "Deleting: " << del->item << endl;
 length--;
 delete del;
}

	
void List::Print() const
{
 node* cur = head;
 while (cur != NULL)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

int List::Find(const itemType item) const
{
 node* cur = head;
 int i = 1;
 while (cur != NULL)
 {
  if (cur->item == item)
  {
   cout << "Item found" << endl;
   break;
  }
  cur = cur->next;
  i++;
 }
 if (cur->item == item)
  return i;
 return -1;
}

void List::DeleteItem(const int pos)
{
 node* cur = head;
 node* temp = head;
 int i = 0;
 while (i < pos - 2)
 {
  cur = cur->next;
  i++;
 }
 temp = cur->next;
 cur->next = temp->next; 
 length--;
 delete temp;
}



#include <iostream>
using namespace std;

#include "list.h"


//Non-recursive functions. I have written them for you.
List::List()
{
 head = NULL;
}

bool List::IsEmpty() 
{
 if (head == NULL)
  return true;
 return false; 
}

void List::PutItemH(itemType item)
{
 node* tmp = new node;
 tmp->item = item;
 tmp->next = head;
 head = tmp;
 tmp = NULL;
}

itemType List::GetItemH() 
{
 return head->item; 
}

void List::DeleteItemH()
{
 node* cur = head;
 head = head->next;
 delete cur;
 cur == NULL;
}

//Write the following functions recursively or in such a way that they use
//recursive functions.  You may add recursive utility functions to the 
//private section of the header (.h) file.

List::~List()
{
 node* cur = head;
 node* next = NULL;
 
 while (cur != NULL)
 {	 
  next = cur->next;
  delete cur;
  cur = next;
 }
}

int List::GetLength()
{
 int length = 1;
 node* cur = head;
 return GetLength(length, cur); 
}

int List::GetLength(int length, node* cur)
{
 if (cur->next == NULL)
  return length;

 return GetLength(length + 1, cur->next);
}

void List::Print( )
{
 node* cur = head;
 Print(cur);
}


void List::PrintRev( )
{
 node* cur = head;
 PrintRev(cur);
}

void List::PrintRev(node* cur)
{
 if (cur == NULL)
  return;
 PrintRev(cur->next);
 cout << cur->item << endl;
}

void List::Print(node* cur) 
{
 
 if (cur == NULL)
  return;
 cout << cur->item << endl;
 Print(cur->next);
}

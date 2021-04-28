//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queue3.h"

PQueue::PQueue() : Queue()
{
 head = NULL;
 tail = NULL;
 length = 0;
}

PQueue::PQueue(PQueue* q) : Queue(q)
{
 head = q->head;
 tail = q->tail;
 length = q->length;
}

void PQueue::Enqueue(itemType newItem)
{ 
 
 if (IsEmpty())
  PutItemH(newItem);
 else 
 {
  if (newItem <= head->item)
   PutItemH(newItem);
  else if (newItem > tail->item)
   PutItemT(newItem);
  else
  {
   PtrTo(newItem);
  }
 }
}

node* PQueue::PtrTo(itemType newItem)
{
 node* insert = new node;
 node* cur;
 node* prev;

 cur = head;
 while (cur->item < newItem)
 {
  prev = cur;
  cur = cur->next;
 }
 insert->next = cur;
 insert->item = newItem;
 prev->next = insert;
 length++;

 return insert;
}
	

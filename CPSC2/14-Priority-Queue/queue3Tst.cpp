#include <iostream>
using namespace std;

#include "queue3.h"


int main()
{

 PQueue* que = new PQueue;
/*
 que->Enqueue(5);
 que->Enqueue(3);
 que->Enqueue(6);
 que->Enqueue(4);
 que->Enqueue(6);
 que->Enqueue(2);
 que->Print();
*/

 PQueue* que2 = new PQueue(que);
 //que2->Print();
 int i = 0;
 while (i < 15)
 {
  que->Enqueue(i);
  i = i + 3;
 }
 que->Print();
 cout << endl;
 que->Enqueue(8);
 que->Print();

 delete que;

 
}

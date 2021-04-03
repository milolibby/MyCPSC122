#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
 //Use of a static list 
 List lst; 
 //Use of a dynamic list
 List* lst1 = new List;
 
 int length;
 bool empty;
 int value;
 

/*
 //Static Test for Print
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << "output should be 0 1 2 3 4 on subsequent lines" << endl;
 cout << endl;

 //Dynamic Test for Print
 cout << "Dynamic Test" << endl;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << "output should be 0 10 20 30 40 on subsequent lines" << endl;
 cout << endl;
*/

/*
 //Static Test for IsEmpty
 empty = lst.IsEmpty();
 cout << "output should be 1" << endl;
 cout << empty << endl;
 
 //Dynamic Test for IsEmpty
 cout << "Dynamic Test" << endl;
 for (int i = 0; i < 5; i++) 
   lst1->PutItemH(i);
 empty = lst1->IsEmpty();
 cout << "output should be 0" << endl;
 cout << empty << endl;
*/

/* 
 //Static Test for GetLength
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 length = lst.GetLength();
 cout << "output should be 5" << endl;
 cout << length << endl;

 //Dynamic Test for GetLength
 cout << "Dynamic Test" << endl;
 for (int i = 0; i < 10; i++) 
   lst1->PutItemH(i);
 length = lst1->GetLength();
 cout << "output should be 10" << endl;
 cout << length << endl;
*/

//Static Test for DeleteItemH and PutItemH
/*
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << "output should be 0 1 2 3 4 on subsequent lines" << endl;
 cout << endl;
 lst.DeleteItemH();
 cout << "output should be 0 1 2 3 on subsequent lines" << endl;
 lst.Print();
 length = lst.GetLength();
 cout << "Length is now " << length << endl;

//Dynamic Test for DeleteItemH and PutItemH
 cout << "Dynamic Test" << endl;
 for (int i = 0; i < 5; i++) 
   lst1->PutItemH(i);
 lst1->Print();
 cout << "output should be 0 1 2 3 4 on subsequent lines" << endl;
 cout << endl;
 lst1->DeleteItemH();
 cout << "output should be 0 1 2 3 on subsequent lines" << endl;
 lst1->Print();
 length = lst1->GetLength();
 cout << "Length is now " << length << endl;
*/

/*
 //Static Test for GetItem
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 cout << "Head Item is (should be 4) ";
 value = lst.GetItemH();
 cout << value << endl;
 //Dynamic Test for GetItem
 cout << "Dynamic Test" << endl;
 for (int i = 0; i < 5; i++) 
   lst1->PutItemH(i*10);
 cout << "Head Item is (should be 40) ";
 value = lst1->GetItemH();
 cout << value << endl;
*/


 //Static Test for Find and DeleteItem
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 value = lst.Find(3);
 cout << "Position of item 3 is (should be 2)" << value << endl;
 lst.DeleteItem(2);
 cout << "Deleting Item in position 2" << endl;
 cout << "output should be 0 1 2 4" << endl;
 lst.Print();

//Dynamic Test for Find and DeleteItem 
 cout << "Dynamic Test" << endl;
 for (int i = 0; i < 5; i++) 
   lst1->PutItemH(i*10);
 lst1->Print();
 value = lst1->Find(20);
 cout << "Position of item 20 is (should be 3)" << value << endl;
 lst1->DeleteItem(3);
 cout << "Deleting Item in position 3" << endl;
 cout << "output should be 0 10 30 40" << endl;
 lst1->Print();



 delete lst1; //necessary to invoke destructor on dynamic list
 cout << endl;
 return 0;
}

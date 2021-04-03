#include <iostream>
using namespace std;

#include "3-ListT.h"


int main()
{
 ListT* lst = new ListT;

/*
 //Test of Constructor
 cout << "Test of Constructor" << endl;
 cout << "********************" << endl;
 cout << "Invoking Constructor Function to create lst1" << endl << endl;
 ListT* lst1 = new ListT;
 cout << "Adding items and displaying list to show an instance of ListT was created" << endl << endl;
 for (int i = 0; i < 5; i++)
  lst1->PutItemH(i);
 lst1->Print();
 int length = lst1->GetLength();
 cout << "The length of the new list is (should be 5)" << endl << length << endl;
 delete lst1;
*/ 
 

/*
 //Test of PutItemH
 cout << "Test of PutItemH" << endl;
 cout << "********************" << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemH(i);
 lst->Print();
 int i = 555; //Test value
 cout << "Using PutItemH to add " << i << " to head of list" << endl << endl;
 lst->PutItemH(i);
 lst->Print();
 cout << i << " should be added to head of list" << endl << endl;
*/

/*
 //Test of Print
 cout << "Test of Print" << endl;
 cout << "********************" << endl;
 cout << "Using Print to print list" << endl << endl;
 lst->Print(); //empty list  
 cout << "Nothing should print (empty list)" << endl << endl;
 cout << "Filling List..." << endl << endl;
 for (int i = 0; i < 6; i++)
  lst->PutItemH(i * 2);
 cout << "Using Print..." << endl << endl;
 lst->Print();
 cout << "Display should be multiples of 2, 0-10" << endl << endl;
*/

/*
 //Test of IsEmpty
 cout << "Test of IsEmpty" << endl;
 cout << "********************" << endl;
 bool empty = lst->IsEmpty();
 cout << "Using IsEmpty to check is list is empty" << endl << endl;
 cout << "List is empty, output should be 1 (true)" << endl;
 cout << empty << endl << endl;
 cout << "Filling list..." << endl << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemH(i);
 cout << "Using IsEmpty..." << endl << endl;
 cout << "List has at least one item, output should be 0 (false)" << endl;
 empty = lst->IsEmpty();
 cout << empty << endl << endl;
*/

/*
 //Test of GetLength
 cout << "Test of GetLength" << endl;
 cout << "********************" << endl;
 int length = lst->GetLength(); //no list
 cout << "Getting length of list using GetLength" << endl << endl;
 cout << "List has no items, length should be 0" << endl;
 cout << "Length of list is: " << length << endl << endl;
 cout << "Filling list..." << endl << endl;
 int size = 5; //Test value
 for (int i = 0; i < size; i++) 
  lst->PutItemH(i);
 cout << size << " items added to the list" << endl;
 length = lst->GetLength();
 cout << endl << "Using GetLength..." << endl << endl;
 cout << "Length of list is: " << length << endl << endl; 
*/

/*
 //Test of GetItemH
 cout << "Test of GetItemH" << endl;
 cout << "********************" << endl;
 lst->PutItemH(1);
 lst->PutItemH(100);
 lst->Print();
 itemType head = lst->GetItemH(); 
 cout << "Getting item head points to using GetItemH" << endl << endl;
 cout << "Head shoud point to item 100" << endl;
 cout << "Head points to item: " << head << endl << endl;
 int test = 30; //Test value
 cout << test << " was added to front of the list using PutItemH" << endl << endl;
 lst->PutItemH(test);
 head = lst->GetItemH();
 cout << "Using GetItemH..." << endl << endl; 
 cout << "Head now points to item: " << head << endl << endl;
*/

/*
 //Test of DeleteItemH
 cout << "Test of DeleteItemH" << endl;
 cout << "********************" << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemH(i*100);
 lst->Print(); 
 cout << "Removing head node of the list using DeleteItemH" << endl << endl;
 lst->DeleteItemH();
 lst->Print();
 cout << "List should have 400 removed" << endl << endl;
 cout << "Using DeleteItemH two more times" << endl << endl;
 for (int i = 0; i < 2; i++)
  lst->DeleteItemH();
 cout << endl;
 cout << "List should just be 0, 100" << endl;
 lst->Print();
*/

/*
 //Test of PutItemT
 cout << "Test of PutItemT" << endl;
 cout << "********************" << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemT(i*10);
 lst->Print();
 int i = 123; //Test value
 cout << "Using PutItemT to add " << i << " to tail of list" << endl << endl;
 lst->PutItemT(i);
 lst->Print();
 cout << i << " should be at tail of list" << endl << endl;
*/

/*
 //Test of GetItemT
 cout << "Test of GetItemT" << endl;
 cout << "********************" << endl;
 lst->PutItemT(5);
 lst->PutItemT(500);
 lst->Print();
 itemType tail = lst->GetItemT(); 
 cout << "Getting item tail points to using GetItemT" << endl << endl;
 cout << "Tail shoud point to item 500" << endl;
 cout << "Tail points to item: " << tail << endl << endl;
 int test = 916; //Test value
 cout << test << " was added to tail of the list using PutItemT" << endl << endl;
 lst->PutItemT(test);
 tail = lst->GetItemT();
 cout << "Using GetItemT..." << endl << endl; 
 cout << "Tail now points to item: " << tail << endl << endl;
*/

/*
 //Test of DeleteItemT
 cout << "Test of DeleteItemT" << endl;
 cout << "********************" << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemT(i*10);
 lst->Print(); 
 cout << "Removing tail node of the list using DeleteItemT" << endl << endl;
 lst->DeleteItemT();
 lst->Print();
 cout << "List should have 40 removed" << endl << endl;
 cout << "Using DeleteItemT two more times" << endl << endl;
 for (int i = 0; i < 2; i++)
  lst->DeleteItemT();
 cout << endl;
 cout << "List should just be 0, 10" << endl << endl;
 lst->Print();
*/

/*
 //Test of FindItem
 cout << "Test of FindItem" << endl;
 cout << "********************" << endl;
 cout << "TEST 1" << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemT(i);
 lst->Print(); 
 cout << "Using FindItem to check how many times list contains target (5)" << endl << endl;
 int count = lst->FindItem(5);
 cout << "5 is in the list " << count << " times " << endl << endl;
 cout << "TEST 2" << endl;
 itemType target = 25;
 cout << target << " is added to the front of the list " << endl << endl;
 lst->PutItemH(target);
 lst->Print();
 cout << "Using FindItem to check how many times list contains target (" << target << ") " << endl << endl;
 count = lst->FindItem(target);
 cout << target << " is in the list " << count << " times" << endl << endl;
 cout << "TEST 3" << endl;
 cout << target << " is added to the front of the list 5 more times" << endl << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemH(target);
 lst->Print();
 cout << "Using FindItem to check how many times list contains target (" << target << ") " << endl << endl;
 count = lst->FindItem(target);
 cout << target << " is in the list " << count << " times" << endl << endl;
*/
 

/*
 //Test of DeleteItem
 cout << "Test of DeleteItem" << endl;
 cout << "********************" << endl;
 cout << "TEST 1" << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemT(i);
 lst->Print(); 
 cout << "Using DeleteItem to delete all instances of target (10)" << endl << endl;
 int count = lst->DeleteItem(10);
 cout << "10 was in the list and therefore was deleted " << count << " times " << endl << endl;
 lst->Print();
 cout << "TEST 2" << endl;
 itemType target = 25;
 cout << target << " is added to the tail of the list " << endl << endl;
 lst->PutItemT(target);
 lst->Print();
 cout << "Using DeleteItem to check how many times list contains target (" << target << ") " << endl << endl;
 count = lst->DeleteItem(target);
 cout << target << " was in the list and therefore was deleted " << count << " times" << endl << endl;
  lst->Print();
 cout << "TEST 3" << endl;
 cout << target << " is added to the front of the list 3 more times" << endl << endl;
 for (int i = 0; i < 3; i++)
  lst->PutItemH(target);
 lst->Print();
 cout << "Using FindItem to check how many times list contains target (" << target << ") " << endl << endl;
 count = lst->DeleteItem(target);
 cout << target << " was in the list and therefore was deleted " << count << " times" << endl << endl;
 lst->Print();
*/

/*
 //Test of Destructor
 cout << "Test of Destructor" << endl;
 cout << "********************" << endl;
 for (int i = 0; i < 5; i++)
  lst->PutItemH(i);
 lst->Print();
*/
 delete lst;
/*
 cout << "Destructor was invoked using delete lst" << endl << endl;
 cout << "Attempting to Print lst..." << endl;
 lst->Print();
*/ 
 return 0;
}


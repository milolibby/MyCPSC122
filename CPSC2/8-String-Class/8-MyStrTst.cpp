/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: February 18, 2021
Assignment: N/A 
Description: Program illustrates using class MyString 
*/

#include "8-MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);
 
/*
 ///Test of myDisplay
 cout << "***************************************" << endl;
 cout << "*****Test 1 myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2  myDisplay*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myDisplay
*/

/*
 ///Test of myStrcpy
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrcpy*****" << endl;
 cout << "static test" << endl;
 cout << "output should be \"Test Passed\"" << endl;
 str1.myStrcpy("Test Passed");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2  myStrcpy*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be \"Test Passed\"" << endl;
 str2->myStrcpy("Test Passed");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrcpy
*/

/*
 ///Test of myStrlen
 int length;
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrlen*****" << endl;
 cout << "static test" << endl;
 cout << "output should be number of characters of command line input" << endl;
 length = str1.myStrlen();
 cout << length << endl;
 cout << endl;
 cout << "*****Test 2  myStrlen*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be number of characters of command line input" << endl;
 length = str2->myStrlen();
 cout << length << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrlen
*/

/*
 ///Test of isEqual
 bool equal = false;
 cout << "***************************************" << endl;
 cout << "*****Test 1 isEqual*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1 if the command line input is \"Test String\", 0 otherwise" << endl;
 equal = str1.isEqual("Test String");
 cout << equal << endl;
 cout << endl;
 cout << "*****Test 2 isEqual*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 1 if the command line input is \"Test String\", 0 otherwise" << endl;
 equal = str2->isEqual("Test String");
 cout << equal << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of isEqual
*/

/*
 ///Test of find
 int index = 0;
 cout << "***************************************" << endl;
 cout << "*****Test 1 find*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the index of its starting positon if command line input contains substring \"Test\", -1 otherwise" << endl;
 index = str1.find("Test");
 cout << index << endl;
 cout << endl;
 cout << "*****Test 2 find*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the index of its starting positon if command line input contains substring \"Test\", -1 otherwise" << endl;
 index = str2->find("Test");
 cout << index << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of find
*/ 

/*
 ///Test of concat
 int index = 0;
 cout << "***************************************" << endl;
 cout << "*****Test 1 concat*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input followed by 12345" << endl;
 str1.concat("12345");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 concat*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input followed by 12345" << endl;
 str2->concat("12345");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of concat
*/

 delete str2;
 return 0;  
}
   
  

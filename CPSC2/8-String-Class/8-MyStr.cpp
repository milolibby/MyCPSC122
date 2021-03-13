#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
 length = strlen(strIn);
 str = new char[length + 1];
 strcpy(str, strIn);
}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
delete []str; 
}

void MyString::myDisplay()
{
 cout << str << endl;
}

void MyString::myStrcpy(char const* strIn)
{
 int i = 0;
 for (i = 0; strIn[i] != '\0'; i++)
  str[i] = strIn[i];
 str[i] = '\0';
}
 
int MyString::myStrlen()
{
 return length;
}

bool MyString::isEqual(char const* strIn)
{
 int i = 0, lengthstrIn = 0;
 bool equal = true;
 
 for (i = 0; strIn[i] != '\0'; i++)
  i = i;
 lengthstrIn = i; 

 if (lengthstrIn != length)
  equal = false;
 i = 0;
 while (equal == true && i < length)
 {
  if (str[i] != strIn[i])
   equal = false;
  i++;
 }
 
 return equal; 
}

int MyString::find(char const* strIn)
{
 int i;
 char* ptr = strstr(str, strIn);
 
 if (*ptr != '\0')
 {
  for (i = 0; i < length; i++)
  {
   if (&str[i] == ptr)
    break;
  }
  return i;
 }
 else 
  return -1;
 
}

void MyString::concat(char const* strIn)
{
 strcat(str, strIn);

}


#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
 inFix = new char[strlen(argvIn) + 1];
 strcpy(inFix, argvIn);
 stk = new Stack;

 if (CheckTokens() == false)
  exit(EXIT_FAILURE);
 
 MakeValueTbl();
 Parse();
 
 if (CheckParens() == false)
  exit(EXIT_FAILURE);
}

Calc::~Calc()
{}

bool Calc::CheckTokens()
{
 bool valid;
 for (int i = 0; i < strlen(inFix); i++)
 {
  valid = false;
  if (inFix[i] == '*' || inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '/') //+-*/
   valid = true;
  
  if (isdigit(inFix[i])) //0..9
   valid = true;

  if (inFix[i] == '(' || inFix[i] == ')') // ()
   valid = true;

  if (isupper(inFix[i])) //A...Z
   valid = true;
  
  if (valid == false)
   return false;
 }


 return true;
}

void Calc::MakeValueTbl()
{
 valueTbl = new int[26];
 for (int i = 0; i < 26; i++)
  valueTbl[i] = 0;
 
 valueIdx = 0;
}

void Calc::Parse()
{
 char cpy[strlen(inFix) + 1]; //cpy of inFix
 char temp[100];
 char* ptr;
 char delimiters[] = " ()+_*/";
 char ch = 'A';
 int i = 0, j = 0;
 
 strcpy(cpy, inFix);
 ptr = strtok(cpy, delimiters);
 
 while (ptr != NULL)
 {
  valueTbl[valueIdx] = atoi(ptr);
  ptr = strtok(NULL, delimiters);
  valueIdx++;
 }
 
 for (i = 0; i < strlen(inFix); i++)
 {
  if (isdigit(inFix[i]))
  {
   temp[j] = ch;
   ch = ch + 1;
   i = FindLast(i);
  }
  else 
   temp[j] = inFix[i];
  j++;
 } 
 strcpy(inFix, temp); 
}

int Calc::FindLast(int cur)
{
 int i = 0;
 while (isdigit(inFix[cur + i]))
  i++;

 return cur + (i - 1);
}

bool Calc::CheckParens()
{
 for (int i = 0; i < strlen(inFix); i++)
 {
  if (inFix[i] == '(')
   stk->Push(inFix[i]);
  if (inFix[i] == ')')
  {
   if (stk->IsEmpty())
    return false;
   stk->Pop();
  }
 }
  if (stk->IsEmpty())
   return true;
 return false;
}

void Calc::DisplayInFix()
{
 for (int i = 0; i < strlen(inFix); i++)
  cout << inFix[i] << endl;
}


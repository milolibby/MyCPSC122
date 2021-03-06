/*
 Name: Milo Libby
 Class: CPSC 122, Section 2
 Date Submitted: Feb 10, 2021
 Assignment: Project 6                                                                    
 Description: This program uses the Affine cipher to
encrypt/decrypt a file
 Notes: None
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void fillMIArray(int MI[]);
void fileOpen(fstream&, string name, char mode);
int keyGen ();
char encrypt (char ch, int alpha, int beta);
char decrypt (char ch, int alpha, int beta, int MI[]);
void fileControl (string keyFile, string fileIn, string fileOut, int mode);
void keyGen (string keyFile);

const int MULTIPLIER = 25;


int main(int argc, char* argv[])
{	

 int mode = -1;
 mode = atoi(argv[1]); // 0 = generate key 1 = encrypt 2 = decrypt

 if (mode == 0)
  keyGen(argv[2]);
 if (mode == 1 || mode == 2)
  fileControl(argv[2], argv[3], argv[4], mode);

}


/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name. 
*/
void fileOpen(fstream& file, string name, char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " file" << endl;
  exit(EXIT_FAILURE);
 }
}


/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
 fstream fin;
 fstream fout;
 int alpha, beta;
 int MI[26];
 char ch;

 fileOpen(fin, keyFile, 'r'); //Key File
 fin >> alpha;
 fin >> beta;
 fin.close();

 fileOpen(fin, fileIn, 'r'); //Plain Text File
 fileOpen(fout, fileOut, 'w'); //Cipher Text File

 if (mode == 1) //encrypt
 {		
  while (fin.peek() != EOF)
  {
   ch = fin.get();
   if (isalpha(ch))
   {
    ch = toupper(ch);
    ch = encrypt(ch, alpha, beta);
   }
    fout.put(ch);
  }
 }
 
 if (mode == 2) //decrypt
 {
  fillMIArray(MI);	
 
  while (fin.peek() != EOF)
  {
   ch = fin.get();
   if (isalpha(ch))
   {
    ch = toupper(ch);
    ch = decrypt(ch, alpha, beta, MI);
   }
  fout.put(ch);
  }  
 }
 
 fin.close();
 fout.close();
}

char encrypt (char ch, int alpha, int beta)
{
 ch = ch - 'A';
 ch = ((ch * alpha) + beta) % 26;
 ch = ch + 'A';

 return ch;
}



char decrypt (char ch, int alpha, int beta, int MI[])
{
 ch = ch - 'A';
 ch = ((ch * MI[alpha]) - (beta * MI[alpha]) + (MULTIPLIER * 26)) % 26;
 ch = ch + 'A';
 return ch;
}

void fillMIArray(int MI[])
{
 ifstream fin;
 fin.open("dictInv.txt");

 int idx = 0;

 while(fin >> MI[idx++]);
 fin.close();
}

/*
Description: Randomly generates and stores alpha and beta values.
The alpha value is randomly drawn from the the set:  {1,3,5,7,11, 17,19,25}
The beta value is randomly drawn from the range: [1..25]  
Output: alpha and beta values on subsequent lines of keyFile
*/
void keyGen (string keyFile)
{
 int alpha = 0;
 int beta;
 int MI[26];
 int i;
 fstream fout;
 srand(time(0));
 
 fileOpen(fout, keyFile, 'w');
 fillMIArray(MI);
 
 beta = (rand() % 25) + 1; // [1...25]
 
 while (alpha == 0)
 {
  i = (rand() % 25) + 1; // [1...25]
  alpha = MI[i];
 }
 
 fout << alpha << endl;
 fout << beta << endl;
 fout.close();
}





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
void encryptFile();
void decryptFile();

const int MULTIPLIER = 25;


int main(int argc, char* argv[])
{	

 keyGen("keyFile");
 encryptFile();
 decryptFile();

 
/*
 ch = encrypt('Z', 17, 12);
 cout << ch << endl;
 cout << ((25 * 3 + 7) % 26) << endl;
 ch = decrypt('V', 17, 12, MI);
 cout << ch << endl;
*/ 

/*int mode = -1;
 mode = atoi(argv[1]); // 0 = generate key 1 = encrypt 2 = decrypt

 if (mode == 0)
  generateKey(argv);
 if (mode == 1)
  encryptFile(argv);
 if (mode == 2)
  decryptFile(argv);
*/
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
 

 /*int i;
 for (i = 0; i < 26; i++) //initialize array to zeros 
  MI[i] = 0;
 
 MI[1] = 1;
 MI[3] = 9;
 MI[5] = 21;
 MI[7] = 15;
 MI[11] = 19;
 MI[17] = 23;
 MI[19] = 11;
 MI[25] = 25;
 */	
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
 ofstream fout;
 srand(time(0));
 
 fillMIArray(MI);
 
 beta = (rand() % 25) + 1; // [1...25]
 
 while (alpha == 0)
 {
  i = (rand() % 25) + 1; // [1...25]
  alpha = MI[i];
 }
 
 fout.open("keyFile");
 fout << alpha << endl;
 fout << beta << endl;
 fout.close();
}

void encryptFile()
{
 fstream fin;
 fstream fout;
 int alpha, beta;
 char ch;
 string text;
	
 fileOpen(fin, "keyFile", 'r'); //Key File
 fin >> alpha;
 fin >> beta;
 fin.close();
		
 fileOpen(fin, "inFile", 'r'); //Plain Text File
 fileOpen(fout, "outFile", 'w'); //Cipher Text File
		
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

 fin.close();
 fout.close();
}

void decryptFile()
{
 fstream fin;
 fstream fout;
 int alpha, beta;
 char ch;
 string text;
 int MI[26];

 fillMIArray(MI);	

 fileOpen(fin, "keyFile", 'r'); //Key File
 fin >> alpha;
 fin >> beta;
 fin.close();
		
 fileOpen(fin, "outFile", 'r'); //Plain Text File
 fileOpen(fout, "inFile2", 'w'); //Cipher Text File
		
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

 fin.close();
 fout.close();
}



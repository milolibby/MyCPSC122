/*
 Name: Milo Libby
 Class: CPSC 122, Section 2
 Date Submitted: Feb 8, 2021
 Assignment: Project 5                                                                    
 Description: This program uses the Caeser cipher to
encrypt/decrypt a file
 Notes: None
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


void fileOpen(fstream& file, string name, char mode);
int keyGen ();
char encrypt (char ch, int key);
char decrypt (char ch, int key);
void stringtoChar(string text, char array[]);
void generateKey(char* argv[]);
void encryptFile(char* argv[]);
void decryptFile(char* argv[]);

int main(int argc, char* argv[])
{	
	int mode = -1;
	mode = atoi(argv[1]); // 0 = generate key 1 = encrypt 2 = decrypt

	if (mode == 0)
		generateKey(argv);
	if (mode == 1)
		encryptFile(argv);
	if (mode == 2)
		decryptFile(argv);
	
}

/*
Description: Generates a key 
Input: file names
Returns: void but outputs key to keyFile
*/
void generateKey(char* argv[])
{
	int key;
	fstream fout;
	fileOpen(fout, argv[2], 'w');
	key = keyGen();
	fout << key << endl;
	fout.close();
}

/*
Description: Encrypts the contents of the input file 
Input: file names
Returns: void but outputs encrypted text to output file
*/
void encryptFile(char* argv[])
{
	fstream fin;
	fstream fout;
	int key;
	char ch;
	string text;
	
	fileOpen(fin, argv[2], 'r'); //Key File
	fin >> key;
	fin.close();
		
	fileOpen(fin, argv[3], 'r'); //Plain Text File
	fileOpen(fout, argv[4], 'w'); //Cipher Text File
		
	while (fin.peek() != EOF)
	{
		ch = fin.get();
		if (isalpha(ch))
		{
			ch = toupper(ch);
			ch = encrypt(ch, key);
		}
		fout.put(ch);
	}

	fin.close();
	fout.close();
}

/*
Description: Decrypts the contents of the input file 
Input: file names
Returns: void but outputs decrypted text to output file
*/
void decryptFile(char* argv[])
{
	fstream fin;
	fstream fout;
	int key, i;
	char ch;
	string text;
	
	fileOpen(fin, argv[2], 'r'); //Key File
	fin >> key;
	fin.close();
		
	fileOpen(fin, argv[3], 'r'); //Plain Text File
	fileOpen(fout, argv[4], 'w'); //Cipher Text File
		
	while (fin.peek() != EOF)
	{
		ch = fin.get();
		if (isalpha(ch))
		{
			ch = toupper(ch);
			ch = decrypt(ch, key);
		}
		fout.put(ch);
	}
		
		fin.close();
		fout.close();
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
Description: Randomly generates an integer in the range: [1..25]
Input: reference to keyFile
Output: writes a randomly generated integer in the range [1..25] to keyFile 
*/
int keyGen ()
{
	int num;
	srand(time(0));
	num = (rand() % 25) + 1; 

	return num;
}

/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt (char ch, int key)
{
	ch = ch - 'A';
	ch = (ch + key) % 26;
	ch = ch + 'A';

	return ch;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt (char ch, int key)
{
	ch = ch - 'A';
	ch = (ch - key + 26) % 26;
	ch = ch + 'A';

	return ch;
}




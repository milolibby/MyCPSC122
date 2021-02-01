/*
 Name: Milo Libby
 Class: CPSC 122, Section 2
 Date Submitted: Feb 2, 2021
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
char keyGen (fstream& fout);
char encrypt (char ch, int key);
char decrypt (char ch, int key);
void stringtoChar(string text, char array[]);

int main(int argc, char* argv[])
{
	fstream fin;
	fstream fout;
	string mode = argv[1]; // 0 = generate key 1 = encrypt 2 = decrypt
	string text;
	char ch;
	int key, i;
	
	if (mode == "0")//Generate Key
	{
		fileOpen(fout, argv[2], 'w'); //Key File
		keyGen(fout);
		fout.close();
	}
	
	if (mode == "1")//Encrypt
	{
		fileOpen(fin, argv[2], 'r'); //Key File
		fin >> key;
		fin.close();
		
		fileOpen(fin, argv[3], 'r'); //Plain Text File
		fileOpen(fout, argv[4], 'w'); //Cipher Text File
		
		getline(fin, text);

		char array[text.size()];
		
		stringtoChar(text, array);
		for (i = 0; i < text.size(); i++)
		{
			ch = array[i];
			if (isalpha(array[i]))
			{
				array[i] = encrypt(ch, key);
			}
		}
		for (i = 0; i < text.size(); i++) //Printing to outfile
		{
		fout << array[i];
		}
		
		fin.close();
		fout.close();
	}
	
	if (mode == "2")//Decrypt
	{
		fileOpen(fin, argv[2], 'r'); //Key File
		fin >> key;
		fin.close();
		
		fileOpen(fin, argv[3], 'r'); //Cypher Text File
		fileOpen(fout, argv[4], 'w'); //Plain Text File
		
		getline(fin, text); 
		char array[text.size()];
		stringtoChar(text, array);
		for (i = 0; i < text.size(); i++)
		{
			ch = array[i];
			if (isalpha(array[i]))
			{
				array[i] = decrypt(ch, key);
			}
		}
		for (i = 0; i < text.size(); i++) //Printing to outfile
		{
		fout << array[i];
		}
		fin.close();
		fout.close();
	}
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
char keyGen (fstream& fout)
{
	int num;
	srand(time(0));
	num = (rand() % 25) + 1; 
	fout << num << endl;

	return 0;
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

/*
Description: Changes a string into a character array
Input: string text, char array[]
Returns: void, but char array[] will be initialized with the individual 
characters from the string
*/

void stringtoChar(string text, char array[])
{
	int i = 0;
	char letter; 

	for (i = 0; i < text.size(); i++)
	{
		letter = text.at(i);
		array[i] = letter;	
	}
}











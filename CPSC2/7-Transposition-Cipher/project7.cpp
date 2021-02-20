/*
 Name: Milo Libby
 Class: CPSC 122, Section 2
 Date Submitted: Feb 15, 2021
 Assignment: Project 7                                                                    
 Description: This program uses the transpositon cipher to
encrypt/decrypt a file
 Notes: None
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void keyGen (string keyFile);
void fileControl (string keyFile, string fileIn, string fileOut, int mode);
char transform(char ch, int encDec[]);
void fileOpen(fstream&, string name, char mode);
void selection_sort(int arr[][2]);
void swap(int pos, int idx_small, int arr[][2]);
int find_small(int start, int arr[][2]);

const int SIZE = 26;

int main(int argc, char* argv[])
{
 int mode = -1;
 mode = atoi(argv[1]); // 0 = generate key 1 = encrypt 2 = decrypt

 if (mode == 0)
  keyGen(argv[2]);
 if (mode == 1 || mode == 2)
  fileControl(argv[2], argv[3], argv[4], mode);

 return 0;
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
Description: Opens key file for writing.  Generates and stores encrypt and decrypt keys in the key file.   This can be stored any way that you like as long as two arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 
*/
void keyGen (string keyFile)
{
 int encKey[SIZE];
 int decKey[SIZE][2];
 bool validate[SIZE];
 int pos = 0, k = 0, i = 0;
 fstream fout;
 srand(time(0));
 
 fileOpen(fout, keyFile, 'w');
 
 for (i = 0; i < SIZE; i++) //every position set to false
  validate[i] = false;
 
 while (pos < SIZE) //encrypt key
 {
  k = rand() % SIZE;
  if (validate[k] == false)
  {
   encKey[pos] = k;
   decKey[pos][0] = k;
   validate[k] = true;
   pos++;
  } 
 }
 for (i = 0; i < SIZE; i++)
  fout << encKey[i] << endl;
                            
 for (i = 0; i < SIZE; i++) //decrypt key
  decKey[i][1] = i; //fill col 1 with corresponding ints for alphabet

 selection_sort(decKey); //sort dec key

 for (i = 0; i < SIZE; i++)
  fout << decKey[i][1] << endl; 
 
 fout.close();
}

/*
Description: Processes files, invokes function to encrypt/decrypt characters
1. Reads key file. Constructs a two arrays, one for encryption, one for decryption.
2. Closes key file
2. Opens the character input file.  This could be plain text or cipher text.
3. Opens the character output file  This could be plain text or cipher text.
4. Reads the input file a character at a time.  Passes transform (see below) the character to be encrypted/decrypted and a reference to  the encrypt or decrypt array, depending on the mode.
5.  Writes a character (encrypted/decrypted/passed over) to the output file.
6. Close the input file and output file
Output: writes a character to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
 fstream fin;
 fstream fout;
 int encKey[SIZE];
 int decKey[SIZE];
 char ch;
 int i = 0;
 

 fileOpen(fin, keyFile, 'r'); //Key File
 for (i = 0; i < SIZE; i++) //read encKey
  fin >> encKey[i];

 for (i = 0; i < SIZE; i++)
  fin >> decKey[i]; //read decKey
 
 fin.close();
 
 fileOpen(fin, fileIn, 'r'); //Plain Text File
 fileOpen(fout, fileOut, 'w'); //Cipher Text File
 
 {		
  while (fin.peek() != EOF)
  {
   ch = fin.get();
   if (isalpha(ch))
   {
    ch = toupper(ch);
    if (mode == 1) //encrypt
     ch = transform(ch, encKey);
    if (mode == 2) //decrypt
     ch = transform(ch, decKey);
   }
    fout.put(ch);
  }
 }
 
 fin.close();
 fout.close();

}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int encDec[])
{
 int i;
 char alphabet[SIZE];
 for (i = 0; i < SIZE; i++) //creates alphabet array
  alphabet[i] = ('A' + i);

 //encrypt
 for (i = 0; i < SIZE; i++)
 {
  if (alphabet[i] == ch)
   break;
 }
 ch = encDec[i] + 'A';
 
 return ch;
}

/*
Description: outer, control loop for selection sort  
Input: array of integers to be sorted along with its length
Output: array is sorted at the end of function
*/
void selection_sort(int arr[][2])
{
 int pass = 0;
 int start = 0;
 int idx_small;

 while(pass < SIZE - 1 )      //option 1 
 {
  int idx_small = find_small(start, arr);
  swap(start,idx_small, arr);
  start++;
  pass++;
 }
}

/*
Description: linear search through an array looking for smallest element
Input: position to start search, array, length of array
Output: returns smallest element in the array
*/
int find_small(int start, int arr[][2])
{
 int idx_small = start;  //candidate smallest
 int next = start + 1;    //start searching here
 while(next < SIZE)
 {
  if (arr[next][0] < arr[idx_small][0]) //we've found a new smallest integer
     idx_small = next;
  next++;                        //look at the next position whether or not
                                //we've found a new smallest 
 }
 return idx_small;
}


/*
Description: swaps the contents of two posiitons in an array 
Input: position whose contents is swapped with smallest,  position of smallest, array 
Output: returns smallest element in the array
*/
void swap(int pos, int idx_small, int arr[][2])
{
 int tmp = arr[pos][0];
 arr[pos][0] = arr[idx_small][0];
 arr[idx_small][0] = tmp;
 tmp = arr[pos][1];
 arr[pos][1] = arr[idx_small][1];
 arr[idx_small][1] = tmp;
}




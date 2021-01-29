/*
 Name: Milo Libby
 Class: CPSC 122, Section 2
 Date Submitted: January 25, 2021
 Assignment: Project 1                                                                    
 Description: Generates prime numbers and 
writes the prime numbers to a file
 Notes: None
*/

#include <iostream> 
#include <fstream>
#include <cstdlib>
using namespace std;

bool isPrime(int num); //Determines whether input integer is prime
void fileOpen(fstream& fout, string name);
void displayPrimes(fstream& fout, int num, int cols);

int main(int argc, char* argv[])
{	
	fstream fout;
	int numPrimes = 0, numCols = 0;
	
	if (argc != 2)
	{
		cout << "Incorrect number of command line arguments" << endl;
		exit(EXIT_FAILURE);	
	}	
	
	fileOpen(fout, argv[1]);

	cout << "How many prime numbers should be generated?" << endl;
	cin >> numPrimes;
	cout << "How many columns should appear in the display?" << endl;
	cin >> numCols;

	displayPrimes(fout, numPrimes, numCols);

	fout.close();	
	
	return 0;
}

/*
	Description: Determines whether input integer is prime
	Input: integer whose primality is to be judged
    Returns: true if num is prime, false otherwise
*/
bool isPrime(int num)
{
	bool prime = true;
	int i = 0;
	
	for (i = 2; i < num; i++){
		if (num % i == 0)
			prime = false;
	}
	
	return prime;
}

/*
	Description: function opens a file 
	Input: file stream output file, name of the file
	Output: void function, but at exit, file stream object is tied to 
	the input file name. 
*/
void fileOpen(fstream& fout, string name)
{
	fout.open(name, ios::out);
	if (fout.fail())
	{
		cout << "Error Opening Output File" << endl;
		exit(EXIT_FAILURE);
	}
}

/*
	Description: function writes number to output file if prime
	Input: output filestream, number of primes, number of columns
	Output: void function, but primes are displayed to fout
	
*/
void displayPrimes(fstream& fout, int numPrimes, int cols)
{
	int ct = 0;
	int currentNum = 2;
	bool prime = false;

	while (ct < numPrimes)
	{
		prime = isPrime(currentNum);
		if (prime)
		{
			fout << currentNum << '\t';
			if (ct % cols == cols -1) //starts a newline when cols are filled at that row
				fout << endl;
		ct++;
		}
		currentNum++;
	}
	
}

#ifndef PA7_H
#define PA7_H

#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <string>
#include <iomanip>
#include <fstream>
#include <ios>
using namespace std;

const int NUM_WORDS = 100;

//functions
string randomWord(const string wordsArray[]); //returns a random word from array
void fillWordsArray(ifstream& infile, string wordsArray[], int size); //fills the string array with words from input file
void stringToChar(string word, char visibleLetters[], int numLetters); //converts randWord into char array
int validateInput(char letter, char array[], int size); //makes sure that user input is valid and follows the rules of the game 
void displayArray(char array[], int size); //displays array contents using a loop
void swapArrayVals(char array[], char letter, int size, char swapChar); //swaps contents in an array with given character (availableLetters[i] = " ")
bool hasWordBeenUsed(string array[], string word, int size); // checks if new word has already been used in previous game

#endif

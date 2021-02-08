/*
Name: Milo Libby
Class: CptS 121, Fall 2020
Date: November 10, 2020
Programming Assignment: PA7
Description: This program simulates a hangman game (WITH BONUS)
Rules of game: 1. Program selects a random word for the user to guess.
2. User guesses one letter at a time until either they guess the word, or they run out of
guesses.
*/


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
void stringToChar(string word, char array[], int numLetters); //converts randWord into char array
int validateInput(char letter, char array[], int size); //makes sure that user input is valid and follows the rules of the game 
void displayArray(char array[], int size); //displays array contents using a loop
void swapArrayVals(char array[], char letter, int size, char swapChar); //swaps contents in an array with given character (availableLetters[i] = " ")
bool hasWordBeenUsed(string array[], string word, int size); // checks if new word has already been used in previous game
void swapwithSymbol(char symbol, char array[], int size);

//simulate a hangman game using loops, arrays, and conditionals
//inputs: char availableLetters[], visibleLetters[], userGuess
// ifstream infile
// int numGuesses = 7, i
// string wordsArray[]
// outputs: string randWord
// int numLetters
// functions: string randomWord(const string wordsArray[]);
// void fillWordsArray(string wordsArray[], int size);
// void stringToChar(string word, char visibleLetters[]);
// void validateInput(char letter);
//Psuedocode:
//open infile
//fill string array from input
//use stringToChar()
//get numLetters using str.size()
//fill visibleLetters[] with - for numLetters
//fill availableLetters[] with letters a-z
//start game loop
//output visible letters
//display availableLetters and guesses left
//ask for guess and use validateInput()
//use loop to check if letters match
	//if match: swap guess into visibleLetters[]
	//else: numGuesses--
//loop until correct word is guessed or no guesses left


int main()
{	
	ifstream infile;
	string wordsArray[NUM_WORDS], usedWords[NUM_WORDS], playAgain = " "; //usedWords stores words from previous games
	fillWordsArray(infile, wordsArray, NUM_WORDS); // fills array from infile
	int numGuesses = 7, i = 0, correctGuesses = 0, k = 0, numLetters = 0;
	bool match = false, quit = false;
	char availableLetters[26], visibleLetters[numLetters], userGuess = ',', copyLetters[numLetters]; //copy to compare guess to word
	bool duplicateWord = false;
	

	for (i = 0; i < NUM_WORDS; i++){ // fills array with default symbol
		usedWords[i] = "*";
	}	
	while (quit != true){ //replayable loop
		char availableLetters[26], visibleLetters[numLetters], userGuess = ',', copyLetters[numLetters]; //copy to compare guess to word
		numGuesses = 7; // resets guesses
		correctGuesses = 0;
		string randWord = randomWord(wordsArray); //gets randomWord
		numLetters = randWord.size(); // number of letters in random word
		stringToChar(randWord, visibleLetters, numLetters); //fills visibleLetters[] with randWord
		
		/*duplicateWord = hasWordBeenUsed(usedWords, randWord, NUM_WORDS);
		while (duplicateWord == true){ //BONUS: gets new randWord if previous was already used
			randWord = randomWord(wordsArray);
			duplicateWord = hasWordBeenUsed(usedWords, randWord, NUM_WORDS);
		}*/
		usedWords[k++] = randWord; //stores used word
		
		for (i = 0; i < numLetters; i++){ // makes copy of array to keep contents
			copyLetters[i] = visibleLetters[i];
	
		}

		for (i = 0; i < numLetters; i++){ //replaces letters with -
			visibleLetters[i] = '-';
		}
		
		stringToChar("abcdefghijklmnopqrstuvwxyz", availableLetters, 26); //fills availableLetters[] with a-z
		
		cout << "The word to guess has " << numLetters << " letters." << endl;
		
		while (numGuesses != 0 && correctGuesses != numLetters){ //main game loop
			match = false; // sets match to false
			
			
			displayArray(visibleLetters, numLetters); // display dashes (------)
			cout << "Available letters: ";
			displayArray(availableLetters, 26); //displays alphabet

			cout << numGuesses << " incorrect guesses remaining." << endl; //guesses remaining
			cout << "Please enter your guess: " << endl;
			cin >> userGuess; //get user guess
			int n;
			n = validateInput(userGuess, availableLetters, 26); //validate input
			if (n == 1){
				cout << userGuess << " is not an available letter." << endl;
				continue;
			}
			for (i = 0; i < numLetters; i++){ //checks for match
				if(copyLetters[i] == userGuess){ //if guess matches a letter
				match = true;
				break;
				}
			}
	
			swapArrayVals(availableLetters, userGuess, 26, ' ');//replaces guessed letter with a space
					if (match == true){ // if theres a match
						cout << "Nice! " << userGuess << " is in the word." << endl;
						for (i = 0; i < numLetters; i++){
							if (copyLetters[i] == userGuess){
								visibleLetters[i] = userGuess;
								correctGuesses++; //increments correct guesses
							}
						}
					}
					else if (match == false) { //if no match
					--numGuesses;
					cout << userGuess << " is not in the word. Too bad. " << numGuesses << " incorrect guesses remaining." << endl;	
					}
		
		}

		if (correctGuesses == numLetters){ //if user wins
			cout << "Congrats, you guessed the word " << randWord << endl; 
		}
		else if (numGuesses == 0) { // if user loses
				cout << "You ran out of guesses, the word was " << randWord << ". Better luck next time..." << endl;
		}
	
		cout << "Do you want to play again? (Enter yes or no)" << endl;
		cin >> playAgain;
	
	 	if (playAgain == "yes"){
			quit = false;
		}
		else if (playAgain == "no") {
			quit = true; 
		} 
	}
		
		//string usedWords[NUM_WORDS];	//FIXME
		cout << usedWords[0] << endl;
		cout << usedWords[1] << endl;
		cout << usedWords[5] << endl;
	return 0;
}






void fillWordsArray(ifstream& infile, string wordsArray[], int size){
	int i = 0;
	infile.open("hangmanwords.txt");
		if(infile.is_open()){
			for(i = 0; i < NUM_WORDS; i++){
				infile >> wordsArray[i];
			}
		}
		else {
			cout << "Failed to open input file..." << endl;
		}	
	infile.close();
}

string randomWord(const string wordsArray[]){
	int n = 0;
	string word = " ";
	srand(time(0));
	n = rand() % 100;
	word = wordsArray[n];

	return word;
}

void stringToChar(string word, char array[], int numLetters){
	int i = 0;
	char letter = '.';
	for(i = 0; i < numLetters; i++){
		letter = word.at(i);
		array[i] = letter;
	}
}

void displayArray(char array[], int size){
	int i = 0;
	for (i = 0; i < size; i++){
		cout << array[i];
	}
	cout << endl;
}

void swapArrayVals(char array[], char letter, int size, char swapChar){
	int i;
	for (i = 0; i < size; i++){
		if (letter == array[i]){
			array[i] = swapChar;
		}
	}

}

int validateInput(char letter, char array[], int size){
	int i;
	bool validInput = false;
	for (i = 0; i < size; i++){
		if(array[i] == letter){
			validInput = true;
		}
	}
		if(validInput == false){
			return 1;
		}
		else {
		return 0;
		}
}		

bool hasWordBeenUsed(string array[], string word, int size){
	int i = 0;
	bool match = false;
	for (i = 0; i < size; i++){
		if (word == array[i]){
			match = true;
			break;
		}
	}
	if (match == true) {
		return true;
	}
	else {
		return false;
	}
}

void swapwithSymbol(char symbol, char array[], int size){
	int i = 0;
	for (i = 0; i < size; i++){
		array[i] = symbol;
	}
}
	








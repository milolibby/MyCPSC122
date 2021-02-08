#include "PA7.h"
/*
Name: Milo Libby
Class: CptS 121, Fall 2020
Date: November 10, 2020
Programming Assignment: PA7
Description: This program simulates a hangman game (WITH BONUS)
Rules of game: 1. Program selects a random word for the user to guess.
2. User guesses one letter at a time until runs out of guesses or wins
*/


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
	string playAgain = " ";
	bool quit = false;
	bool duplicateWord = false;
	while (quit != true){ //replayable loop
		ifstream infile;
		string wordsArray[NUM_WORDS], usedWords[NUM_WORDS]; //usedWords stores words from previous games
		fillWordsArray(infile, wordsArray, NUM_WORDS); // fills array from infile
		int numGuesses = 7, i = 0, correctGuesses = 0, k = 0;
		bool match = false;
		string randWord = randomWord(wordsArray); //gets randomWord
		int numLetters = randWord.size(); // number of letters in random word
		char availableLetters[numLetters], visibleLetters[numLetters], userGuess = ',', copyVisibleLetters[numLetters]; //copy to compare guess to word
		stringToChar(randWord, visibleLetters, numLetters); //fills visibleLetters[] with randWord
		
		duplicateWord = hasWordBeenUsed(usedWords, randWord, NUM_WORDS);
		while (duplicateWord == true){ //BONUS: gets new randWord if previous was already used
			randWord = randomWord(wordsArray);
			duplicateWord = hasWordBeenUsed(usedWords, randWord, NUM_WORDS);
			
		}
		
		usedWords[k] = randWord; //stores used word
		k++;
		for (i = 0; i < numLetters; i++){ // makes copy of array to keep contents
			copyVisibleLetters[i] = visibleLetters[i];
	
		}

		for (i = 0; i < numLetters; i++){ //replaces letters with -
			visibleLetters[i] = '-';
		}
	
		stringToChar("abcdefghijklmnopqrstuvwxyz", availableLetters, 26); //fills availableLetters[] with a-z
	
		cout << "The word to guess has " << numLetters << " letters." << endl;
		/*displayArray(copyVisibleLetters, numLetters); */ //test
	
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
				if(copyVisibleLetters[i] == userGuess){ //if guess matches a letter
				match = true;
				break;
				}
			}
	
			swapArrayVals(availableLetters, userGuess, 26, ' ');//replaces guessed letter with a space
				
					if (match == true){ // if theres a match
						cout << "Nice! " << userGuess << " is in the word." << endl;
						for (i = 0; i < numLetters; i++){
							if (copyVisibleLetters[i] == userGuess){
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
			continue;
		}
		else {
			quit = true;
			
		} 
		quit = true;
		
		
	}
	return 0;
}







	

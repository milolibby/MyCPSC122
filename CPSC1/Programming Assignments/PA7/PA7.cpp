#include "PA7.h"
void fillWordsArray(ifstream& infile, string wordsArray[], int size){
	int i = 0;
	infile.open("input.txt");
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

void stringToChar(string word, char visibleLetters[], int numLetters){
	int i = 0;
	char letter = '.';
	for(i = 0; i < numLetters; i++){
		letter = word.at(i);
		visibleLetters[i] = letter;
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






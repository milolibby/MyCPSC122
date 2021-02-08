#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main () {
	//1. Problem Requirements
	// create a program that displays a random number 1-6 simulating a dice roll

	//2. analyze
	// inputs: numRolls (number of random numbers displayed)
	//  
	// outputs : randNum (random number outputted)
	// relationships: numRolls is the number of randNum outputted
	//
	//3. psuedo code
	// intitilize values
	// ask for numRolls from user
	// generate random number using for and while loops 
	//4. implement

	int numRolls;
	int randNum;
	int i;

	srand(time(0));

	cout << "Enter an integer for how many times you want the dice to be rolled" << endl;
	cin >> numRolls;
	//for loop
	for (i = 1; i <= numRolls; i++){
		cout << rand() % 6 + 1 << endl;
	}

	return 0;
}


	

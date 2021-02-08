
/*
Name: Milo Libby
Class: CptS 121, Fall 2020
Date: October 10, 2020
Programming Assignment: PA4
Description: This program uses randomly generated numbers to simulate a craps game 
*/

#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;

//simulate a craps game using loops and conditionals
//inputs: initialBalance wagerVal
// outputs: currentBalance die1 die2 diceSum
//intialize vars
//display rules to user
//ask for initialBalance
// validate input
//create game loop
//ask if they want to keep playing
//ask for initial wager
//validate input
//sum of 2 random dice roll using srand()
//while loop if it goes to a point 
//press enter to continue
//
int main()
{
	int initialBalance = 0, currentBalance = 0, initialWager = 0, i = 0, die1 = 0, die2 = 0, diceSum = 0, addWager = 0, pointDice = 0;//variables
	string gameRules = "";
	char quit = '.';

	gameRules = "Welcome to Craps, here are the rules of the game: A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw 	(called craps), the player loses (i.e. the house wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point. To win, you must continue rolling the dice until you make your point. The player loses by rolling a 7 before making the point."; 
	cout << gameRules << endl;	//display rules

	cout << "What is your initial bank balance: " << endl;
	cin >> initialBalance;
	
	while (cin.fail() || initialBalance <= 0) { //validating input
		cin.clear();
		cin.ignore(256, '\n');
		
		cout << "Invalid bank balance! Please enter a valid amount: " << endl;
		cin >> initialBalance;
		
	}
	
	currentBalance = initialBalance;
	
	while (currentBalance > 0) {
		
		// giving user option to quit 
		cout << "Enter $ to play or q to exit the game" << endl;
		cin >> quit;
				if (quit == 'q') {
					break;
				}
			

						
		cout << "Current bank balance: " << currentBalance << endl;
		cout << "Please enter your initial wager: " << endl;
		cin >> initialWager;
			while (cin.fail() || initialWager > currentBalance) { //validating input
				cin.clear();
				cin.ignore(256, '\n');
		
				cout << "Invalid wager! Please enter a valid amount: " << endl;
				cin >> initialWager;
		
			}
		srand(time(0));
		die1 = (rand() % 6) + 1;//inital roll
		die2 = (rand() % 6) + 1; 
		int sumDice = 0;
		sumDice = die1 + die2;
		cout << "Sum " << sumDice << "(Die1: " << die1 << " Die2: " << die2 << ")" << endl;
		if (sumDice == 7 || sumDice == 11) {	//win 
			cout << "Congrats you won!" << endl; 
			currentBalance = currentBalance + (initialWager * 2); //gives prize money
		}
		else if (sumDice == 2 || sumDice == 3 || sumDice == 12) { //lose
			cout << "Sorry, you lost..." << endl; 
			currentBalance = currentBalance - initialWager;
		}
		
		else if (sumDice == 4 || sumDice == 5 || sumDice == 8 || sumDice == 6 || sumDice == 9 || sumDice == 10) {
			while (!sumDice == pointDice) {
				cout << "You need to roll to make your point (" << sumDice << ")..."<< endl;
				cout << "Press enter to continue..." << endl; // prompts user to press the enter key to continue
				cin.ignore(256, '\n');
				cin.get();
				currentBalance -= initialWager;
				cout << "Total wager so far: " << initialWager << endl;
				cout << "Available bank balance: " << currentBalance << endl;
				cout << "Please enter your wager: " << endl;
				cin >> addWager;
				initialWager += addWager; 
			
				while (cin.fail() || addWager > currentBalance) { //validating input
					cin.clear();
					cin.ignore(256, '\n');
		
					cout << "Invalid wager! Please enter a valid amount: " << endl;
					cin >> addWager;
				}
				die1 = (rand() % 6) + 1;
				die2 = (rand() % 6) + 1;
				pointDice = die1 + die2;
				if (pointDice == 7){
					cout << "You lost..." << endl;
					break;
				}
			}
			
				if (pointDice == sumDice){
					cout << "Congrats, you made your point (" << pointDice << ")!" << endl;
		}	
		}
		}
	return 0;

}



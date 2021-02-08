#include "PA8.h"
/*
Name: Milo Libby
Class: CptS 121, Fall 2020
Date: Nov 19, 2020
Programming Assignment: PA8
Description: This program simulates a battleship game where the user plays agaisnt the computer
*/

int main() {
	ofstream outfile;
	char p1Board[NUM_ROWS][NUM_COLS]; // 10 x 10 chars
	char p2Board[NUM_ROWS][NUM_COLS]; 
	char invisibleBoard[NUM_ROWS][NUM_COLS];
	char trashbinBoard[NUM_ROWS][NUM_COLS];
	int startingPlayer = 0, enteredNum = 0, whosTurn = 0, cord1 = 0, cord2 = 0;
	double numHits1 = 0.0, numHits2 = 0.0, numMisses1 = 0.0, numMisses2 = 0.0;
	int usedNums1[NUM_ROWS][NUM_COLS];
	int usedNums2[NUM_ROWS][NUM_COLS];
	bool win = false, shipSunk = false, hit = false;
	string shipHit = " ", whichPlayer = " ";

	outfile.open("battleship.log"); //open outfile
	if (!outfile.is_open()){
		cout << "Couldn't open output file..." << endl;
		return 1;
	}
	initializeBoard(p1Board, NUM_ROWS, NUM_COLS); //fills p1Board with '-'
	initializeBoard(p2Board, NUM_ROWS, NUM_COLS); //fills p2Board with '-'
	initializeBoard(invisibleBoard, NUM_ROWS, NUM_COLS); //fills invisivleBoard with '-'
	
	welcomeScreen();// welcome message / rules
	
	cout << "Please select from the following menu: " << endl;
	cout << "1. Enter positions of ships manually. " << endl;
	cout << "2. Allow the program to randomly select positions of ships. " << endl << endl;

	cin >> enteredNum; // 1 or 2
	cout << endl;

	if (enteredNum == 1){ // manually place ships
		manuallyPlaceShipsOnBoard(p1Board, usedNums1, NUM_ROWS, NUM_COLS, shipNames, shipSymbols, shipSizes);
	}
	else {
		randomlyPlaceShipsOnBoard(p1Board, usedNums1, NUM_ROWS, NUM_COLS, shipNames, shipSymbols, shipSizes, 1); // randomly generate p1 board ships
	}
	randomlyPlaceShipsOnBoard(p2Board, usedNums2, NUM_ROWS, NUM_COLS, shipNames, shipSymbols, shipSizes, 2); // randomly generate p2 board

	startingPlayer = selectWhoStartsFirst(whichPlayer, whosTurn); //returns 1 or 2 for who starts
	cout << whichPlayer << " has been randomly selected to go first." << endl << endl;
	whosTurn = startingPlayer; 

	while (win == false){ //game loop
		cout << "Player1's Board:" << endl << endl; 
		displayBoard(p1Board, NUM_ROWS, NUM_COLS); //displays p1 Board
	
		cout << "Player2's Board:" << endl << endl; 
		displayBoard(invisibleBoard, NUM_ROWS, NUM_COLS); // display p2 Board 
		if (whosTurn == 1){ //if player1s turn
			whosTurn = 1; // player1 turn to shoot
			shipHit = checkShot(outfile, p2Board, invisibleBoard, NUM_ROWS, NUM_COLS, hit);	// checks p1 shot on p2 Board
		
			if (hit == true){ //if there was a hit
				numHits1++;
				shipSunk = checkIfSunkShip(p2Board, NUM_ROWS, NUM_COLS, shipHit, shipNames, shipSymbols, shipSizes);//check if p2 board sunk
				if (shipSunk == true){ // if ship sank
					outfile << "Sunk " << shipHit << "!" << endl;
					cout << "The " << shipHit << " has been sunk!" << endl << endl;
					win = isWinner(p2Board, NUM_ROWS, NUM_COLS); // checks if p1 is the winner
				}
			}
			else {
			numMisses1++;
			}
			if (win == true){ //if win break out of loop
				break;
			}
			cout << "Player1's Board:" << endl << endl; 
			displayBoard(p1Board, NUM_ROWS, NUM_COLS); //displays p1 Board
	
			cout << "Player2's Board:" << endl << endl;; 
			displayBoard(invisibleBoard, NUM_ROWS, NUM_COLS); // displays blank p2 board
			whosTurn = 2;
		}

		if (whosTurn == 2){ //player2 turn to guess
			shipHit = randomShot(outfile, p1Board, NUM_ROWS, NUM_COLS, hit); //player2 random shot on user and checks shot
			if (hit == true){ //if there was a hit
				numHits2++;
				shipSunk = checkIfSunkShip(p1Board, NUM_ROWS, NUM_COLS, shipHit, shipNames, shipSymbols, shipSizes);//check if p1 board sunk
				if (shipSunk == true){ //if ship is sunk
					cout << "The " << shipHit << " has been sunk!" << endl << endl;
					win = isWinner(p1Board, NUM_ROWS, NUM_COLS); // checks if p2 is the winner
				}
			}
			else {
				numMisses2++;
			}
			if (win == true){ //if win break out of loop
				break;
			}
			whosTurn = 1;
		}
		cout << "Hit enter to continue the game!" << endl;
		cin.ignore(256, '\n');
		cin.get();
		system("clear");
	}
	if (whosTurn == 1){ 
		whichPlayer = "Player1";
	}
	else {
		whichPlayer = "Player2";
	}
	cout << whichPlayer << " Wins!" << endl << endl;
	outfile << endl << endl << endl;	
	if (whosTurn == 1){
		outfile << "Player1 wins, Player2 loses" << endl;
	}
	else {
		outfile << "Player2 wins, Player1 loses" << endl;
	}
	outfile << "*** Player1 Stats ***" << endl; //player1 stats
	outputStats(outfile, numHits1, numMisses1); 
	
	outfile << "*** Player2 Stats ***" << endl;
	outputStats(outfile, numHits2, numMisses2); 

	cout << "Statistics outputted to logfile successfully!" << endl;
	outfile.close(); // close output file
	return 0;
}



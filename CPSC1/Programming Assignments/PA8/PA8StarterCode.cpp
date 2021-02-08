/*
Name: Milo Libby
Class: CptS 121, Fall 2020
Date: Nov 19, 2020
Programming Assignment: PA8
Description: This program simulates a battleship game where the user plays agaisnt the computer
*/

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;

const string shipNames[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
const char shipSymbols[] = {'c', 'b', 'r', 's', 'd'};
const int shipSizes[] = {5, 4, 3, 3, 2};

void initializeBoard(char[NUM_ROWS][NUM_COLS], int rows, int cols);//fills board with '-'
void displayBoard(const char[NUM_ROWS][NUM_COLS], int rows, int cols);//displays board
void  welcomeScreen();// welcome message / rules
int selectWhoStartsFirst(string& whichPlayer, int& whosTurn); // returns 1 or 2 randomly
void manuallyPlaceShipsOnBoard(char[NUM_ROWS][NUM_COLS], int usedCords[NUM_ROWS][NUM_COLS],  int rows, int cols, const string shipNames[], const char shipSymbols[], const int shipSizes[]); //manual
void randomlyPlaceShipsOnBoard(char arr[NUM_ROWS][NUM_COLS], int usedNums[NUM_ROWS][NUM_COLS], int rows, int cols, const string shipNames[], const char shipSymbols[], const int shipSizes[], int whichPlayer); //ships placed randomly
string checkShot(ofstream& outfile, char[NUM_ROWS][NUM_COLS], char invisibleBoard[NUM_ROWS][NUM_COLS], int rows, int cols, bool& hit); //determines if the shot taken was a hit or a miss and updates board for player1
bool isWinner(const char[NUM_ROWS][NUM_COLS], int rows, int cols); //checks if winner exists
bool checkIfSunkShip(char[NUM_ROWS][NUM_COLS], int rows, int cols, string shipHit, const string shipNames[], const char shipSymbols[], const int shipSizes[]); // checks if sunk ship
void outputStats(ofstream& outfile, double numHits, double numMisses); //writes stats to log
string randomShot(ofstream& outfile, char p1Board[NUM_ROWS][NUM_COLS], int rows, int cols, bool& hit); //player2 random shot on user and checks shot


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
/*************************************************************
* Function:displayBoard()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: displays a character array
* Input parameters:const char array
* Returns: void
*`Post: displays entire array
*************************************************************/
void displayBoard(const char arr[NUM_ROWS][NUM_COLS], int rows, int cols) {
	int i, j;
	cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
	for (i = 0; i < rows; i++) {
		cout << i << " ";
		for (j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/*************************************************************
* Function: initializeBoard()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: initialized the boards with '-'
* Input parameters: board you want initialized
* Returns: void
*`Post: changes all array elements to '-'
*************************************************************/
void initializeBoard(char arr[NUM_ROWS][NUM_COLS], int rows, int cols) {
	int i, j;
	
	// outer loop iterates over each row
	for (i = 0; i < rows; i++) {
		// inner loop iterates over int in arr[i] (row)
		for (j = 0; j < cols; j++) {
			arr[i][j] = '-';
		}
	}
}
/*************************************************************
* Function: welcomeScreen()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: displays welcome message and rules to user
* Input parameters: none 
* Returns: void
*`Post:displays rules 
*************************************************************/
void  welcomeScreen(){
	cout << "***** Welcome to Battleship! *****" << endl;
	cout << endl;
	cout << "Rules of the Game: " << endl;
	cout << "1. This is a two player game." << endl;
	cout << "2. Player1 is you and Player2 is the computer. " << endl;
	cout << "3. Each player has their own board where they place their 5 ships " << endl;	
	cout << "4. Each player switches off guessing coordinates until someone sinks all of their oppenent's ships" << endl;
	cout << "Good luck!" << endl;
	
	cout << "Hit enter to start the game!" << endl;
	cin.ignore(256, '\n'); 
	system("clear");
}
/*************************************************************
* Function: randomShot()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: Randomly chooses who starts in the game
* Input parameters: string and int passed by reference
* Returns: randNum 
*`Post: returns 1 or 2 randomly
*************************************************************/
int selectWhoStartsFirst(string& whichPlayer, int& whosTurn){ // returns 1 or 2 randomly
	srand(time(0));
	int randNum = (rand() % 2) + 1;
	if (randNum == 1){
		whichPlayer = "Player1";
	}
	else if (randNum == 2){
		whichPlayer = "Player2";
	}
	whosTurn = randNum;
	return randNum;
}
/*************************************************************
* Function: manuallyPlaceShipsonBoard()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: the user manually places the ships on the board one cell at a time
* Input parameters: player1 const arrays
* Returns: void
*`Post:fills the board with ships to start the game
*************************************************************/
void manuallyPlaceShipsOnBoard(char arr[NUM_ROWS][NUM_COLS], int usedCords[NUM_ROWS][NUM_COLS], int rows, int cols, const string shipNames[], const char shipSymbols[], const int shipSizes[]){
	int cord1, cord2, i, j;
	for (i = 0; i < 5; i++){
	cout << "Please enter the " << shipSizes[i] << " cells to place the " << shipNames[i] << " across (Press enter after each cell with a space between the numbers): " << endl;
		for (j = 0; j < shipSizes[i]; j++){
			cin >> cord1;
			cin >> cord2;
			
			while (usedCords[cord1][cord2] == 1 || cord1 > 9 || cord2 > 9){
				if(usedCords[cord1][cord2] == 1){
					cout << "You already placed a ship on " << cord1 << " " << cord2 << ". Enter a vacant cell" << endl;
				}
				else if(cord1 > 9 || cord2 > 9){
					cout << cord1 << " " << cord2 << " is outside the boundaries. Enter valid cell" << endl;
				}
				cin >> cord1;
				cin >> cord2;
				
			}
			arr[cord1][cord2] = shipSymbols[i];	
			usedCords[cord1][cord2] = 1;
		}
	}
	cout << "All of your ships have been placed!" << endl;
	
}
/*************************************************************
* Function: =randomlyPlaceShipsOnBoard()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: Places ships randomly for p1 or p2
* Input parameters: distinguish which players board is being filed
* Returns: Void
*************************************************************/
void randomlyPlaceShipsOnBoard(char arr[NUM_ROWS][NUM_COLS], int usedNums[NUM_ROWS][NUM_COLS], int rows, int cols, const string shipNames[], const char shipSymbols[], const int shipSizes[], int whichPlayer){ //ships placed randomly
	int cord1, i, j;
	int cord2;
	int vertOrHorizontal;
	string player = " ";

	if (whichPlayer == 1){ //different random seed
		srand(time(0)); 
	}

	for (i = 0; i < 5; i++){
		for (j = 0; j < shipSizes[i]; j++){
			if(j == 0){
				vertOrHorizontal = (rand() % 2) + 1; //whether to increase cord1 or cord2
				cord1 = rand() % 10;
				cord2 = rand() % 10;
			
				while (usedNums[cord1][cord2] == 1 ){
					cord1 = rand() % 10;
					cord2 = rand() % 10;
				}
			}
			
			arr[cord1][cord2] = shipSymbols[i];	
			usedNums[cord1][cord2] = 1;
			if (vertOrHorizontal == 1){ //vert
				++cord1;
				while (usedNums[cord1][cord2] == 1 || cord1 > 9){ //if space already taken or outside array
					--cord1;
				}
			}
			else { //horizontal
				++cord2;
				while (usedNums[cord1][cord2] == 1 || cord2 > 9){ //if space already taken or outside array
					--cord2;
				}
			}
		}	
	}
	if (whichPlayer == 1){
		player = "Player1 (User's)";
	}
	else {
		player = "Player2 (Computer's)";
	}
	cout << player << " board has been generated" << endl << endl;
}
/*************************************************************
* Function: checkShot()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: checks the shot that the user guessed, writes move to outfile, and adjusts boards
* Input parameters: p2board bool hit
* Returns: Void
* Pre: bool hit is passed by reference
*************************************************************/
string checkShot(ofstream& outfile, char arr[NUM_ROWS][NUM_COLS], char invisibleBoard[NUM_ROWS][NUM_COLS], int rows, int cols, bool& hit){
	int i, j, cord1, cord2;
	string shipHit = " ";
	string hitOrMiss = " ";
	srand(time(0));
	cout << "Enter a target: " << endl << endl; //get target from user
	cin >> cord1;
	cin >> cord2;
	while (arr[cord1][cord2] == 'm' || arr[cord1][cord2] == '*'){ //makes sure cords havent been guessed already
		cout << cord1 << "," << cord2 << " has already been guessed, enter a valid target: " << endl << endl;
		cin >> cord1;
		cin >> cord2;
	}
	system("clear"); //clears terminal
	
	if (arr[cord1][cord2] != '-' && arr[cord1][cord2] != 'm'){ // if hit
		cout << cord1 << "," << cord2 << " is a hit!" << endl << endl;
		hit = true;
		hitOrMiss = "hit";
		switch (arr[cord1][cord2]){ //determines which ship was hit
			case 'c':
				shipHit = "carrier";
				break;
			case 'b':
				shipHit = "battleship";
				break;
			case 'r':
				shipHit = "cruiser";
				break;
			case 's':
				shipHit = "submarine";
				break;
			case 'd':
				shipHit = "destroyer";
				break;
			default:
				break;
		}
		
		arr[cord1][cord2] = '*';
		invisibleBoard[cord1][cord2] = '*';
	}
	else { // if miss
		cout << cord1 << "," << cord2 << " is a miss!" << endl << endl;
		arr[cord1][cord2] = 'm';
		invisibleBoard[cord1][cord2] = 'm';		
		hit = false;
		hitOrMiss = "miss";
	}

	outfile << "Player1: " << cord1 << "," << cord2 << " " << hitOrMiss << endl;
	return shipHit;
}
/*************************************************************
* Function: isWinner()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: Checks if player has any ships left
* Input parameters: Number of hits and misses from the player.
* Returns: win = true if there are no ships left
*************************************************************/
bool isWinner(const char arr[NUM_ROWS][NUM_COLS], int rows, int cols){
	int i, j;
	bool win = true;
	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++) {
			if (arr[i][j] == 'c' || arr[i][j] == 'r' || arr[i][j] == 's' || arr[i][j] == 'd' || arr[i][j] == 'b'){// if any of the ships still stand 
				win = false;
				break;
			}

			
		}
	}
	
	return win;
}
/*************************************************************
* Function: checkIfSunkShip()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: Checks if a ship has sunk
* Input parameters: shipHit, const arrays
* Returns: true if ship has sunk
*************************************************************/
bool checkIfSunkShip(char arr[NUM_ROWS][NUM_COLS], int rows, int cols, string shipHit, const string shipNames[], const char shipSymbols[], const int shipSizes[]){ // checks if ship sunk
	bool ifSunkShip = true;
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 5; i++){
		if (shipHit == shipNames[i]){
			while (ifSunkShip == true && k < rows){
				for (j = 0; j < cols; j++){
					if (arr[k][j] == shipSymbols[i]){
						ifSunkShip = false;
						break;
					}
				
				}
				k++;
			}
		}
	}		
				
	return ifSunkShip;
}
/*************************************************************
* Function: randomShot()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: Randomly choose coordinates, checks if a ship is hit, writes to outfile, 
and adjusts the board accordingly
* Input parameters: player1 board.
* Returns: string shipHit
* Pre: writes to outfile
*`Post: moves are outputted to battleship.log
*************************************************************/
string randomShot(ofstream& outfile, char arr[NUM_ROWS][NUM_COLS], int rows, int cols, bool& hit){ //player2 random shot on user
	int i, j, cord1, cord2;
	string shipHit = " ";
	bool empty = false;
	string hitOrMiss = " ";
	srand(time(0));
	while (empty == false){ //makes sure cords havent been guessed already
		cord1 = rand() % 10;
		cord2 = rand() % 10;
		empty = true;
		if (arr[cord1][cord2] == 'm' || arr[cord1][cord2] == '*'){
			empty = false;
		}
	}
	cout << "Player2 selects: " << cord1 << "," << cord2 << endl << endl;
	
	if (arr[cord1][cord2] != '-' && arr[cord1][cord2] != 'm'){ // if hit
		cout << cord1 << "," << cord2 << " is a hit!" << endl << endl;
		hit = true;
		hitOrMiss = "hit";
		switch (arr[cord1][cord2]){ //determines which ship was hit
			case 'c':
				shipHit = "carrier";
				break;
			case 'b':
				shipHit = "battleship";
				break;
			case 'r':
				shipHit = "cruiser";
				break;
			case 's':
				shipHit = "submarine";
				break;
			case 'd':
				shipHit = "destroyer";
				break;
			default:
				break;
		}
		
		arr[cord1][cord2] = '*';
	}
	else { // if miss
		cout << cord1 << "," << cord2 << " is a miss!" << endl << endl;
		arr[cord1][cord2] = 'm';
		hit = false;
		hitOrMiss = "miss";
	}
	outfile << "Player2: " << cord1 << "," << cord2 << " " << hitOrMiss << endl;
	return shipHit;
}

/*************************************************************
* Function: outputStats()
* Date Created: 11/17/20
* Date Last Modified: 11/18/20
* Description: Writes stats to log
* Input parameters: Number of hits and misses from the player.
* Returns: Void
* Pre: numHits and numMisses is counted during the game loop
*`Post: stats are outputted to battleship.log
*************************************************************/
void outputStats(ofstream& outfile, double numHits, double numMisses){//writes stats to log
	outfile << "Number Hits: " << numHits << endl;
	outfile << "Number Misses: " << numMisses << endl;
	outfile << "Total Shots: " << numMisses + numHits << endl;
	outfile << "Hit/Miss Ratio: " << (numHits / numMisses) * 100 << "%" << endl;
}




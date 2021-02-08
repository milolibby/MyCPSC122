#ifndef PA8_H
#define PA8_H

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

//functions
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


#endif

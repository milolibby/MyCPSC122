#include <iostream>
#include <string> 
#include <cmath>
using namespace std;

int main ()
{

//first introduce the quiz and ask for name 
//Question 1-2, 9 multiple choice
//Question 3-4 numeric value
//Question 5-7 Boolean true false
//Question 8, 10 numeric value
// keep score

	cout << "Welcome to the NBA Fan Quiz, Please type your first name" << endl;

	string firstName;
	cin >> firstName;
	cout << "Hi " << firstName << ". There will be 10 questions in this quiz and you will get one point for each correct 	answer, Goodluck!" << endl;
	
	int userScore = 0;
	char userInput;
//Question 1
	
	cout << "1) What team did Micheal Jordan play on?  Please enter a character a-e.\n a) Chicago Bulls\n b) Utah Jazz\n c) Boston Celtics\n d) Sac Kings \n e) Dallas Mavs" << endl;
	
	cin >> userInput;
	
	if (userInput == 'a') {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	else {
	cout << "Sorry you are wrong, the correct answer is the Chicago Bulls" << endl;
}

//Question 2

	cout << "2) Which NBA Franchise has not won an NBA Championship?   Please enter a character a-e.\n a) Golden State \n b) LA Lakers\n c) Boston Celtics\n d) New Orleans Pelicans \n e) Dallas Mavs" << endl;

	cin >> userInput;
	
	if (userInput == 'd') {
	cout << "That's Right!" << endl;
	userScore = userScore + 1;
}
	else {
	cout << "Sorry you are wrong, the correct answer is the New Orleans Pelicans" << endl;
}
	

//Question 3 numeric response

	int numInput;
	
	cout << "3) How many different teams has Lebron James played for in his career so far?  Please enter an integer." << 	endl;

	cin >> numInput;

	if (numInput == 3) {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	
	else {
	cout << "Sorry you are wrong, the correct answer is 3 (Lakers, Cavs, Heat)" << endl;
}

//Question 4 numeric response

	cout << "4) How many championship rings does Kobe Bryant have? Please enter an integer." << endl;
	
	cin >> numInput;

	if (numInput == 5) {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	
	else {
	cout << "Sorry you are wrong, the correct answer is 5" << endl;
}

//Question 5 boolean response

	bool userAnswer; 
	cout << "5) James Harden was drafted by the Houston Rockets, true or false? Please enter 1 for true or 0 for false." << endl;
	cin >> userAnswer;
	if (userAnswer == false) {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	else {
	cout << "Sorry you are wrong, he was drafted by Oklahoma City Thunder" << endl;
}

//Question 6 

	cout << "6) Russell Westbrook has won the regular season MVP award in his career, true or false? Please enter 1 for true or 0 for false." << endl;
	cin >> userAnswer;
	if (userAnswer == true) {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	else {
	cout << "Sorry you are wrong, he won league MVP in 2017" << endl;
}

//Question 7

	cout << "7) The Golden State Warriors were the 2019 NBA Champs, true or false? Please enter 1 for true or 0 for false." << endl;
	cin >> userAnswer;
	if (userAnswer == false) {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	else {
	cout << "Sorry you are wrong, the Toronto Raptors beat them in the finals" << endl;
}
	
//Question 8 numeric response

	cout << "8) What jersey number does Lebron James currently wear? Please enter an integer." << endl;
	
	cin >> numInput;

	if (numInput == 23) {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	
	else {
	cout << "Sorry you are wrong, the correct answer is 23" << endl;
}


//Question 9 multiple choice

	cout << "9) Who is the current league MVP?  Please enter a character a-e.\n a) Steph Curry\n b) Lebron James\n c) Paul George\n d) Giannis Antetokounmpo \n e) Alex Caruso" << endl;
	
	cin >> userInput;
	
	if (userInput == 'd') {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	else {
	cout << "Sorry you are wrong, the correct answer is the Giannis Antetokounmpo" << endl;
}

//Question 10 numeric response

	cout << "10) How many teams are there in the NBA? Please enter an integer." << endl;
	
	cin >> numInput;

	if (numInput == 30) {
	cout << "You are correct!" << endl;
	userScore = userScore + 1;
}
	
	else {
	cout << "Sorry you are wrong, the correct answer is 30" << endl;
}

//User gets score

	cout << firstName << ", you have completed the NBA Fan Quiz! You have a score of " << userScore << " out of 10!" << endl;

	if (userScore > 7) {
	cout << "You are a superfan! Very impressive!" << endl;
}

	else if (userScore <= 7 && userScore >= 4) {
	cout << "You are a casual fan! Good job!" << endl;
}

	else if (userScore < 4) {
	cout << "You must be a new fan of the NBA! Watch some more games!" << endl;
}

	return 0;

}

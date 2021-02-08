#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// SW development method
	// 1. problem requirements
	// Write a program that predicts the score needed on a final exam to achieve a desired grade in a course
	
	// 2. analyze the problem
	// inputs: letterGrade, minAverage, currentAverage, finalPercent
	// outputs: scoreNeeded
	// relationships: scoreNeeded = (minAverage - (currentAverage * (1 - finalPercent))) / finalPercent
	// finalPercent = finalPercent / 100 
	
	// 3. design the algorithm (pseudocode)
	// ask for and store minAverage, currentAverage, letterGrade, finalPercent
	// convert finalPercent to a decimal
 	// calculate and output scoreNeeded
	
	// 4. implement the algorithm (C++)
	double scoreNeeded;
	double minAverage;
	double currentAverage;
	double finalPercent;
	char letterGrade;
	
	cout << "Enter desired grade: " << endl;
	cin >> letterGrade; 

	cout << "Enter minimum average required: " << endl;
	cin >> minAverage;

	cout << "Enter current average in course: " << endl;
	cin >> currentAverage; 

	cout << "Enter how much the final counts\nas a percentage of the course grade: " << endl;
	cin >> finalPercent;

	finalPercent = finalPercent / 100; 
	scoreNeeded = (minAverage - (currentAverage * (1 - finalPercent))) / finalPercent;

	cout << "You need a score of " << scoreNeeded << " on the final to get a " << letterGrade << "." << endl;


	// 5. test the completed program
	// test with values from sheet
	
	
	// 6. maintain the program

	return 0;
}

#include <iostream>
#include <cmath> // for pow()

using namespace std;

double getUserWeight(void);
double getUserHeight(void);
double computeBMI(double heightInches, double weightPounds);
void displayBMI(double BMI);

int main() {
	// the software development method
	// 1. specify the problem requirements
	// Program calculates BMI given weight and height
	// and displays optimal, under, or overweight
	// 2. analyze the problem
	// inputs: weight in pounds, height in inches
	// outputs: BMI category
	// relationships between the inputs and the outputs: 
	// BMI = weightPounds * 703 / heightInches squared
	// 3. design an algorithm to solve the problem
	// PSEUDOCODE
	// prompt for height and weight
	// get and store height and weight
	// calculate BMI
	// determine BMI category
	// display BMI category
	// 4. implement the algorithm	
	double weightPounds = 0.0;
	double heightInches = 0.0;
	double BMI = 0.0;
	
	weightPounds = getUserWeight();
	heightInches = getUserHeight();
	
	
	// compute BMI
	BMI = computeBMI(weightPounds, heightInches);
	displayBMI(BMI);
	return 0;
}

double getUserWeight(void) {
	int weightPounds = 0;
	cout << "Enter the weight in pounds: ";
	cin >> weightPounds;
	
	return weightPounds;
}
	
double getUserHeight(void) {
	int heightInches =0;
	int heightFeet = 0;
	cout << "Enter the height in feet and inches (e.g. 5 4).";
	cin >> heightFeet;
	cin >> heightInches;
	
	heightInches = heightInches + (heightFeet * 12);
	return heightInches;
}
	
double computeBMI(double weightPounds, double heightInches){
	double BMI;
	BMI = weightPounds * 703 / pow(heightInches, 2);
	
	return BMI;
}
void displayBMI(double BMI) {

	cout << BMI << endl; 
	
	
	if (BMI < 18.5) {
		cout << "Underweight" << endl;
	}
	else if (BMI <= 25) // only way to get here is if BMI >= 18.5 
	{
		cout << "Normal" << endl;
	}
	else { // BMI >= 18.5 && BMI > 25 so really BMI > 25
		cout << "Overweight" << endl;
	}	
}

/*
Name: Milo
Class: Cpsc 121, Fall 2020
Date: October 28, 2020
Programming Assignment: PA6

*/

#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <iomanip>
#include <cmath>

using namespace std;

double read_double(ifstream& infile); //Reads one double precision number from the input file.
int read_integer(ifstream& infile); //Reads one integer number from the input file.
double calculate_sum(double number1, double number2, double number3,double number4, double number5); //Finds the sum of 5 number and returns the result
double calculate_mean(double sum, int number); //Determines the mean through the calculation sum / number and returns the result
double calculate_deviation(double number, double mean);//Determines the deviation of number from the mean. The deviation may be calculated as number - mean
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);//Determines the variance 
double calculate_standard_deviation(double variance);//Calculates the standard deviation as sqrt(variance) 
double find_max(double number1, double number2, double number3, double number4, double number5); //Determines the maximum number out of the five inputs  
double find_min(double number1, double number2, double number3, double number4, double number5); //Determines the minimum numbe
void print_double(ofstream& outfile, double number);//Prints a double precision number (to the hundredths place) to an output file

int main()
{
int IDnum = 0, classStanding1 = 0, classStanding2 = 0, classStanding3 = 0, classStanding4 = 0, classStanding5 = 0;
double sumGPAs = 0.0, sumClass = 0.0, sumAges = 0.0, meanGPA = 0.0, meanClass = 0.0, meanAges = 0.0, deviation1 = 0.0, deviation2 = 0.0 , deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0, variance = 0.0, standardDev = 0.0, max = 0.0, min = 0.0, age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0, gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0;
ifstream infile;
ofstream outfile;

infile.open("input.dat");
	if (infile.is_open()) {
		cout << "Successfully opened input file" << endl;
	}
	else {
		cout << "Failed to open input file" << endl;
		exit(-1);
	}
	
	outfile.open("output.dat");
	if (outfile.is_open()) {
		cout << "Successfully opened output file" << endl;
	}
	else {
		cout << "Failed to open output file" << endl;
		exit(-1);
	}

	IDnum = read_integer(infile);
	gpa1 = read_double(infile);
	classStanding1 = read_integer(infile);
	age1 = read_double(infile);
	
	//cout << IDnum << endl << gpa1 << endl << classStanding1 << endl << age1 << endl; 

	IDnum = read_integer(infile);
	gpa2 = read_double(infile);
	classStanding2 = read_integer(infile);
	age2 = read_double(infile);
	
	//cout << IDnum << endl << gpa2 << endl << classStanding2 << endl << age2 << endl; 

	IDnum = read_integer(infile);
	gpa3 = read_double(infile);
	classStanding3 = read_integer(infile);
	age3 = read_double(infile);
	
	//cout << IDnum << endl << gpa3 << endl << classStanding3 << endl << age3 << endl; 

	IDnum = read_integer(infile);
	gpa4 = read_double(infile);
	classStanding4 = read_integer(infile);
	age4 = read_double(infile);
	
	//cout << IDnum << endl << gpa4 << endl << classStanding4 << endl << age4 << endl; 

	IDnum = read_integer(infile);
	gpa5 = read_double(infile);
	classStanding5 = read_integer(infile);
	age5 = read_double(infile);
	
	//cout << IDnum << endl << gpa5 << endl << classStanding5 << endl << age5 << endl; 

	sumGPAs = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	sumClass = calculate_sum(classStanding1, classStanding2, classStanding3, classStanding4, classStanding5);
	sumAges = calculate_sum(age1, age2, age3, age4, age5);

	meanGPA = calculate_mean(sumGPAs, 5);
	meanClass = calculate_mean(sumClass, 5);
	meanAges = calculate_mean(sumAges, 5);


	print_double(outfile, meanGPA);
	print_double(outfile, meanClass);
	print_double(outfile, meanAges);
	outfile << endl;
	
	deviation1 = calculate_deviation(gpa1, meanGPA);
	deviation2 = calculate_deviation(gpa2, meanGPA);
	deviation3 = calculate_deviation(gpa3, meanGPA);
	deviation4 = calculate_deviation(gpa4, meanGPA);
	deviation5 = calculate_deviation(gpa5, meanGPA);
	
	variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5);
	standardDev = calculate_standard_deviation(variance);

	print_double(outfile, standardDev);
	
	min = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
	print_double(outfile, min);
	print_double(outfile, max);





	infile.close();
	outfile.close();
	
	return 0;
}


double read_double(ifstream& infile){
	double gpa;
	infile >> gpa;
	return gpa;
}

int read_integer(ifstream& infile){
	int num;
	infile >> num;
	return num;
}

double calculate_sum(double number1, double number2, double number3,double number4, double number5){
	return number1 + number2 + number3 + number4 + number5;
}

double calculate_mean(double sum, int number){
	if (number == 0){
		return -1;
	}
	return sum / number;
}

double calculate_deviation(double number, double mean){
	return number - mean;
}

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number){
	double devSum; 
	devSum = pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2)  + pow(deviation5, 2);
	return devSum / number;
}
	
double calculate_standard_deviation(double variance){
	return sqrt(variance);
}

double find_max(double number1, double number2, double number3, double number4, double number5){
	double num;
	int n;
	double max = 0;
	
		if (number1 > max){
			max = number1;
		}
		
		if (number2 > max){
			max = number2;
		}
		
		if (number3 > max){
			max = number3;
		}
		
		if (number4 > max){
			max = number4;
		}
		
		if (number5 > max){
			max = number5;
		}
	
	
	return max;
}
		
double find_min(double number1, double number2, double number3, double number4, double number5){
	double min = 100000;
		if (number1 < min){
			min = number1;
		}
		
		if (number2 < min){
			min = number2;
		}
		
		if (number3 < min){
			min = number3;
		}
		
		if (number4 < min){
			min = number4;
		}
		
		if (number5 < min){
			min = number5;
		}
		
	return min;
}

void print_double(ofstream& outfile, double number){
	outfile << fixed << setprecision(2) << number << endl;
}






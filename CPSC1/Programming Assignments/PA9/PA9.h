d#ifndef PA9_H
#define PA9_H

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <ios>
#include <iomanip>
using namespace std;

//functions
double read_double(ifstream& infile); //Reads one double precision number from the input file.
int read_integer(ifstream& infile);//Reads one integer number from the input file.
string read_string(ifstream& infile); //Reads one string from the input file.
int store_data_sets(ifstream& infile,  string& idNum, vector<int>& standing, vector<double>& gpa, vector<double>& age, string& maxID, string& minID); //Returns the number of records read 
int calculate_sum(vector<int> numbers); //Finds the sum of any number of values passed
double calculate_sum(vector<double> numbers); //Finds the sum of any number of values passed
double calculate_mean(double sum, int number); //Determines the mean through the calculation sum / number
int calculate_count_above_mean(double mean, vector<double> GPAs); //Calculates the count of GPAs greater than the mean GPA
int calculate_count_below_mean(double mean, vector<double> GPAs); //Calculates the count of GPAs lower than the mean GPA
void calculate_deviation(vector<double> Gpas, double mean, vector<double>& deviation); // Determines the individual deviations from the mean for any num
double calculate_variance(vector<double> deviation, int number); //calculates variance
double calculate_standard_deviation(double variance); //Calculates the standard deviation as sqrt(variance)
double find_max(vector<double> gpas); //finds max out of given numbers
double find_min(vector<double> gpas); //Determines the number for any number of values 
void print_formatted_double(ofstream& outfile, double number, int precision); //Prints a double precision number (to the hundredths place) to an output file

#endif




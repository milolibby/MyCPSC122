#include "PA9.h"
/*
Name: Milo Libby
Class: CptS 121, Fall 2020
Date: Nov 19, 2020
Programming Assignment: PA9
Description: Write a program that processes student ID strings and numbers, corresponding to an unknown
number of student records read in from a file, and writes the required results to an output file
*/

int main() 
{
	int numRecords = 0, countAbove = 0, countBelow = 0;
	double sumGpas = 0.0, sumStandings = 0.0, sumAges = 0.0, meanGpas = 0.0, meanStandings = 0.0, meanAges = 0.0, variance = 0.0, standardDeviation = 0.0, maxGpa, minGpa;
	string idNums = ".", maxID = ".", minID = " "; //student ID number
	vector<double> gpas; //student GPA
	vector<double> deviation; //vector of deviations
	vector<int> standings; //Class standing
	vector<double> ages; //student Age
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
	
	numRecords = store_data_sets(infile, idNums, standings, gpas, ages, maxID, minID); //stores data in vectors

	sumGpas = calculate_sum(gpas); //sum of gpas
	sumStandings = calculate_sum(standings);
	sumAges = calculate_sum(ages);

	meanStandings = calculate_mean(sumStandings, numRecords);
	meanAges = calculate_mean(sumAges, numRecords);
	meanGpas = calculate_mean(sumGpas, numRecords); //mean of gpas

	countAbove = calculate_count_above_mean(meanGpas, gpas); //counts number of scores above the mean
	countBelow = calculate_count_below_mean(meanGpas, gpas); //counts number of scores below the mean
	calculate_deviation(gpas, meanGpas, deviation); //calculates deviation
	variance = calculate_variance(deviation, numRecords); //calculates variance
	standardDeviation = calculate_standard_deviation(variance); //calculates standard deviation
	maxGpa = find_max(gpas);
	minGpa = find_min(gpas);
	
	
	outfile << numRecords << endl << endl;
	
	print_formatted_double(outfile, meanGpas, 2);
	outfile << countAbove << endl;
	outfile << countBelow << endl;
	print_formatted_double(outfile, meanStandings, 2); 
	print_formatted_double(outfile, meanAges, 2); 
	outfile << endl;
	
	print_formatted_double(outfile, standardDeviation, 2); //prints standard deviation to hundreths
	outfile << minGpa << endl;
	outfile << minID << endl;
	outfile << maxGpa << endl;
	outfile << maxID << endl;




	infile.close();
	outfile.close();

	return 0;
}

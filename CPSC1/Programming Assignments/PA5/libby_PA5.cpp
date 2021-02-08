/*
Name: Milo
Class: Cpsc 121, Fall 2020
Date: October 4, 2020
Programming Assignment: PA3
Description:Reads an inputfile and creates an outputfile that displays a roadtrip analyzer
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// task: open gainesville_roadtrip.txt for reading
	// check that you successfully opened file
	ifstream inputFile;
	ofstream outputFile;	
	string line, city1 = " ", city2 = " ", originCity = " ", trashbin = " ", endCity = " ", longestCity1, longestCity2, longestDayCity;
	int numWaypoints = 0, longestDist = 0, longestDays = 0, numDays = 0;
	double cityDist = 0.0, totalMiles = 0.0, averageDays = 0.0, averageDist = 0.0, totalDays = 0.0; 
	
	inputFile.open("sacroadtrip.txt");
	if (inputFile.is_open()) {
		cout << "Successfully opened input file" << endl;
	}
	else {
		cout << "Failed to open input file" << endl;
		exit(-1);
	}
	
	outputFile.open("sacroadtripstats.txt");
	if (outputFile.is_open()) {
		cout << "Successfully opened output file" << endl;
	}
	else {
		cout << "Failed to open output file" << endl;
		exit(-1);
	}
	cout << "Welcome to the road trip analyzer program! Roadtrip origin, destination, waypoints, distance between waypoints in meters, and number of days spent at each waypoint will be read in from a file. The program writes to an output file the distance in miles between each waypoint on the trip and statistics about the trip. Enjoy!" << endl;
	
	getline(inputFile, originCity);
	cout << "Reading in road trip stop information from sacroadtrip.txt..." << endl;
	cout << "Roadtrip origin: " << originCity << endl;
		// process
	// there is only one origin the file
	// read it before the loop
	// task: read in each line of the file using getline()
	// print out the line to the console
	city2 = originCity; 

	while (!inputFile.eof())  {
		// hint: currently each iteration reads one line
		// change it so each iteration reads on waypoint triple
		// meters (int), waypoint name (string, days (int)
		city1 = city2;
		getline(inputFile, trashbin);
		inputFile >> cityDist;
		getline(inputFile, trashbin);
		getline(inputFile, city2);
		inputFile >> numDays;
		getline(inputFile, trashbin);
	
		cout << "Processing waypoint " << city2 << " (" << numDays << " days)..." << endl; 
		
		
		outputFile << city1 << " to " << city2 << ": " << cityDist * 0.000621371 << " miles" << endl; //meters to miles
		numWaypoints++; 
		totalDays += numDays;
		totalMiles += cityDist;
		if (cityDist > longestDist) { //  longest distance
			longestDist = cityDist;
			longestCity1 = city1;
			longestCity2 = city2;
		}
		
		if (numDays > longestDays) { // most days
			longestDays = numDays;
			longestDayCity = city2;
		}
		if (!inputFile.good()) { // when int fails 
			
			cout << "Roadtrip Destination: " << city2 << endl;
			cout << "Writing stop stats to gainesville_roadtrip_stats.txt..." << endl;
			cout << "Closing files... " << endl;
			break;
		}
	}
			averageDays = totalDays / numWaypoints;
			averageDist = totalMiles * .000621371 / numWaypoints;
			outputFile << "**Road Trip Stats**" << endl;
			outputFile << "Number of waypoints on roadtrip:  " << numWaypoints - 1 << endl;
			outputFile << "Number of days on roadtrip: " << totalDays - numDays << endl; //gets rid of extra numDays
			outputFile << "Total miles traveled on roadtrip: " << totalMiles * .000621371 << endl;
			outputFile << "Longest roadtrip distance between waypoints is " << longestCity1 << " to " << longestCity2 << " " << longestDist * .000621371 << " miles " << endl;
			outputFile << "Longest roadtrip days at one waypoint is " << longestDayCity << ": "<< longestDays << " days" << endl;
			outputFile << "Average roadtrip distance between stops is: " << averageDist << endl;
			outputFile << "Average roadtrip days at one waypoint: " << averageDays << endl;
	
		
	inputFile.close();
	outputFile.close();

	return 0;
}

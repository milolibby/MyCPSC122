#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ofstream outFS;
	ifstream inFS;
	string driverName;
	string destStore;
	string trashbin;
	int dropTime;
	int totalTime = 0;
	int numDrivers = 0;
	inFS.open("trucks.txt");
	outFS.open("truck-destinations.txt");
	
	if (!inFS.is_open()) {
      cout << "Could not open file trucks.txt." << endl;
      return 1;
	}
	
	if (!outFS.is_open()) {
      cout << "Could not open file truck-destinations.txt." << endl;
      return 1;
   }
		outFS << "Truck Drop-offs Report" << endl;
	while (!inFS.eof()){
		getline(inFS, driverName);
		getline(inFS, destStore);
		inFS >> dropTime;
		getline(inFS, trashbin);
		++numDrivers;
		getline(inFS, trashbin);
		totalTime = totalTime + dropTime;
		outFS << destStore << endl;
	}
		outFS << endl;
		outFS << "Number of Trucks: "<< numDrivers << endl;
		outFS <<  "Average dropoff time: " << totalTime / numDrivers << endl;
		

	outFS.close();
	return 0;
}

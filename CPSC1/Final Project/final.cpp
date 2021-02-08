//[INCLUDE NAME BLOCK ON EACH OF YOUR 3 FILES]
/*
 Name:Milo Libby
 Class: CPSC 121, Fall 2020
 Lab Final Exam
 Notes:		[Insert any notes here, e.g., if you comment out code to get it to compile,
			 note the line number and what you attempted to do to fix your code]
*/

//Required includes -- you should be able to complete this exam without additional includes
// and you should not modify/remove any of these!
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

//enumerated data type used for menu option selections
enum MenuOptions { OPEN_INPUT_FILE = 1, OPEN_OUTPUT_FILE, READ_TRUCK_DATA, DISPLAY_PACKAGE_INFO, COMPUTE_PACKAGE_STATS, DISPLAY_PACKAGE_STATS, DISPLAY_ALL_DATA, WRITE_ALL_DATA, ORDER66, EXIT_PGM };

//required prototype - leave unmodified. You must still place this in it's proper file
void cls(void); //function clears screen on both Linux and Windows OSes

//required function prototypes
bool openInputFile(ifstream& infile, const string filename);
bool openOutputFile(ofstream& outfile, const string filename);
void displayFileStatus(bool fileStatus, const string filename);
void processPackages(ifstream& infile, vector<int>& packageIds, vector<double>& packageWeights, vector<string>& packageDimensions, string& driverName);
bool verifyPackagesSize(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions);
void displayPackageInformation(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName);
void computePackageStats(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, int& heaviestId, double& heaviestWeight, double& avgWeight);
bool verifyStatsCompute(int heaviestId, double heaviestWeight, double avgWeight);
void displayPackageStats(int heaviestId, double heaviestWeight, double avgWeight);
void writePackageInfoAndStats(ofstream& outfile, vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, int heaviestId, double heaviestWeight, double avgWeight);

/*OPTIONAL - if you implement any extra functions include them BELOW the required functions
			ALSO make note in your note comment block at the top of the file(s) that you have
			created additional function prototypes/definitions

	POSSIBLE ADDITIONAL FUNCTION PROTOTYPES (not required to complete this program)
*/

//program main
int main()
{
	//package contains
	/*
		int id;
		double weight;
		string dimensions; //LxWxH
	*/

	//Parallel Vectors
	vector<int> packageIds;
	vector<double> packageWeights;
	vector<string> packageDimensions;
	//Input and Output stream variables
	ifstream infile;
	ofstream outfile;
	//string variables
	string inputFilename = "truckload.txt", outputFilename = "truckloadstats.txt", driverName = "";
	//stats variables
	int heaviestId = 0;
	double heaviestWeight = 0, avgWeight = 0;
	//menu choice variable
	int userMenuSelection = -1;
	//keeping track of file open status
	bool inputFileIsOpen = false, outputFileIsOpen = false;
	//keeping track of validating data
	bool packageDataAreValid = false, packageStatsAreValid = false;

	
	
	







	//MENU LOOP
	do
	{
		do
		{
			cout << "\nPlease choose from the following menu (1-9) to handle truck load processing.\n";
			cout << "1) Open input file for reading\n";
			cout << "2) Open output file for writing\n";
			cout << "3) Read in truck file and process data\n";
			cout << "4) Display the package information\n";
			cout << "5) Compute package statistics for the current truck load\n";
			cout << "6) Display package statistics for the current truck load\n";
			cout << "7) Display the package information AND package statistics\n";
			cout << "8) Write the package information AND package statistics to the output file\n";
			cout << "9) Generate a programming joke\n";
			cout << "10) Quit\n";
			cout << ">> ";
			cin >> userMenuSelection;
			if (userMenuSelection > 10)
			{
				cls(); //clears the screen
				cout << "Invalid Option\n";
			}
		} while (userMenuSelection < 1 || userMenuSelection > 10);
		cout << "\n";
		cls(); //clears the screen

		/* START HINT BLOCK
		-:HINT:-

				 ██╗  ██╗██╗███╗   ██╗████████╗
			  ██╗██║  ██║██║████╗  ██║╚══██╔══╝██╗
		█████╗╚═╝███████║██║██╔██╗ ██║   ██║   ╚═╝█████╗
		╚════╝██╗██╔══██║██║██║╚██╗██║   ██║   ██╗╚════╝
			  ╚═╝██║  ██║██║██║ ╚████║   ██║   ╚═╝
				 ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝

		For each of the following case statements you  should ONLY need
		to write a combinations of

		1) function calls
		2) if-else statements
		3) cout statements

		END HINT BLOCK*/

		switch (static_cast<MenuOptions>(userMenuSelection))
		{
		case OPEN_INPUT_FILE: //Open input file for reading
			inputFileIsOpen = openInputFile(infile, inputFilename); // your code here
			displayFileStatus(inputFileIsOpen, inputFilename);
			//(BONUS) read filename from user input
			break;
		case OPEN_OUTPUT_FILE: //Open output file for writing
			outputFileIsOpen = openOutputFile(outfile, outputFilename); // your code here
			displayFileStatus(outputFileIsOpen, outputFilename);//(BONUS) read filename from user input
			break;
		case READ_TRUCK_DATA: //Read in truck file for processing
			if (inputFileIsOpen){
				processPackages(infile, packageIds, packageWeights, packageDimensions, driverName);// your code here
				packageDataAreValid = verifyPackagesSize(packageIds, packageWeights, packageDimensions);
			}
			else {
				cout << "Input File Not Open" << endl;
			}
			break;
		case DISPLAY_PACKAGE_INFO: //Display the package information in forward order
			if (packageDataAreValid) {
				displayPackageInformation(packageIds, packageWeights, packageDimensions, driverName);// your code here
			}
			else {
				cout << "Package Data Not Valid" << endl;
			}
			break;
		case COMPUTE_PACKAGE_STATS: //Compute package statistics for the current truck load
			if (packageDataAreValid) {
				computePackageStats(packageIds, packageWeights, packageDimensions, heaviestId, heaviestWeight, avgWeight);// your code here
				packageStatsAreValid = verifyStatsCompute(heaviestId, heaviestWeight, avgWeight);
			}
			else {
				cout << "Package Data Not Valid" << endl;
			}
			break;
		case DISPLAY_PACKAGE_STATS: //Display package statistics for the current truck load
			if (packageStatsAreValid){
				displayPackageStats(heaviestId, heaviestWeight, avgWeight);// your code here
			}
			else {
				cout << "Package Stats Not Valid" << endl;
			}
			break;
		case DISPLAY_ALL_DATA: //Display the package information in forward order AND statistics about the packages
			if (packageStatsAreValid && packageDataAreValid){
				displayPackageInformation(packageIds, packageWeights, packageDimensions, driverName);// your code here
				displayPackageStats(heaviestId, heaviestWeight, avgWeight);// your code here
			}
			else {
				cout << "Package Stats or Data is Not Valid" << endl;
			}
			break;
		case WRITE_ALL_DATA: //Write the package information in forward order AND statistics about the packages to an output file
			if (packageStatsAreValid && packageDataAreValid){
				writePackageInfoAndStats(outfile, packageIds, packageWeights, packageDimensions, driverName, heaviestId, heaviestWeight, avgWeight);// your	
			}
			else {
				cout << "Package Stats or Data is Not Valid" << endl;
			}
			break;
		case ORDER66:
			//Does nothing unless you want it to :-)
			cout << "This starter code...\n Ba dum tsss!";
			//https://www.youtube.com/watch?v=ObpcGNCU944
			break;
		case EXIT_PGM:
			//Do nothing, we will exit the loop
			break;
		default:
			cout << "Invalid Option\n";
			break;
		}

	} while (userMenuSelection != 10);

	//CLOSE FILES
	infile.close();
	outfile.close();
	return 0;
}

/*Leave this function UNMODIFIED -- you still need to place it
	in the appropriate file */
	/*************************************************************
	 * Function: cls()
	 * Description: This function should clear the console screen
	 * for both Windows and Linux command prompt / terminal windows
	 *************************************************************/
void cls(void)
{
	system("cls||clear");
	return;
}
/*LEAVE THIS FUNCTION UNMODIFIED*/

bool openInputFile(ifstream& infile, const string filename){
	bool open = false;
	infile.open(filename);
	if (infile.is_open()) {
	open = true;
	}
	
	else {
		
		return -1;
	}
	return open;
}

bool openOutputFile(ofstream& outfile, const string filename){
	bool open = false;
	outfile.open(filename);
	if (outfile.is_open()) {
		
	open = true;
	}
	
	else {
		return -1;
	}
	return open;
}

void displayFileStatus(bool fileStatus, const string filename){
	if (fileStatus){
		cout << "Successfully opened " << filename << endl;
	}
	else {
		cout << "Failed to open " << filename << endl;
	}
	

}

void processPackages(ifstream& infile, vector<int>& packageIds, vector<double>& packageWeights, vector<string>& packageDimensions, string& driverName){
	int ids;
	double weights;
	string trashbin, dimensions;

	getline(infile, driverName);
	//getline(infile, trashbin);
	while (!infile.eof()) {
		infile >> ids;
		infile >> weights;
		getline(infile, trashbin);
		getline(infile, dimensions);
		packageIds.push_back(ids);
		packageWeights.push_back(weights);
		packageDimensions.push_back(dimensions);	
		getline(infile, trashbin);
		
		// cout << ids << endl << weights << endl << dimensions << endl << driverName << endl; TEST
	}

}

bool verifyPackagesSize(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions){
	bool sameSize = false;
	if (packageIds.size() == packageWeights.size() && packageWeights.size() == packageDimensions.size() && packageDimensions.size() > 0){
		sameSize = true;
	}

	return sameSize;


}

void displayPackageInformation(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName){
	int i = 0;
	cout << "Driver: " << driverName << endl;
	cout << "Number of packages: " << packageIds.size() << endl;
	cout << "Package Information" << endl;
	cout << "_____________________" << endl;
	
	for (i = 0; i < packageIds.size(); i++){
		
		cout << "Package ID: " << setprecision(2) << fixed <<packageIds.at(i) << endl;
		cout << "Package Weight: " << setprecision(2) << fixed <<packageWeights.at(i) << endl;
		cout << "Package Dimensions: " << setprecision(2) << fixed << packageDimensions.at(i) << endl << endl;
	}


}
	
void computePackageStats(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, int& heaviestId, double& heaviestWeight, double& avgWeight){
	int i = 0;
	double totalWeight = 0;
	heaviestWeight = packageWeights.at(0);
	
	for (i = 0; i < packageWeights.size(); ++i){
		if (packageWeights.at(i) > heaviestWeight){
			heaviestWeight = packageWeights.at(i);
			heaviestId = packageIds.at(i);
		}
	totalWeight += packageWeights.at(i);	
	}

	avgWeight = totalWeight / packageWeights.size();

}

bool verifyStatsCompute(int heaviestId, double heaviestWeight, double avgWeight){
	bool notZero = false;
	if (heaviestId != 0 && heaviestWeight != 0 && avgWeight != 0){
		notZero = true;
	}

	return notZero;
}

void displayPackageStats(int heaviestId, double heaviestWeight, double avgWeight){
	cout << "Package Stats" << endl;
	cout << "_____________" << endl;
	cout << "ID of heaviest package: " << setprecision(2) << fixed << heaviestId << endl;
	cout << "Weight of heaviest package: " << setprecision(2) << fixed << heaviestWeight << endl;
	cout << "Average weight of packages on truck: " << setprecision(2) << fixed << avgWeight << endl;

}

void writePackageInfoAndStats(ofstream& outfile, vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, int heaviestId, double heaviestWeight, double avgWeight){
	int i = 0;
	outfile << "Driver: " << driverName << endl;
	outfile << "Number of packages: " << packageIds.size() << endl;
	outfile << "Package Information" << endl;
	outfile << "_____________________" << endl;
	
	for (i = 0; i < packageIds.size(); i++){
		
		outfile << "Package ID: " << setprecision(2) << fixed <<packageIds.at(i) << endl;
		outfile << "Package Weight: " << setprecision(2) << fixed <<packageWeights.at(i) << endl;
		outfile << "Package Dimensions: " << setprecision(2) << fixed << packageDimensions.at(i) << endl << endl;
	}
	
	outfile << "Package Stats" << endl;
	outfile << "_____________" << endl;
	outfile << "ID of heaviest package: " << setprecision(2) << fixed << heaviestId << endl;
	outfile << "Weight of heaviest package: " << setprecision(2) << fixed << heaviestWeight << endl;
	outfile << "Average weight of packages on truck: " << setprecision(2) << fixed << avgWeight << endl;

}


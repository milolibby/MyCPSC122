I#include "PA9.h"

/*************************************************************
* Function: read_double()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: This function reads one double precision number from the input file
* Input parameters: ifstream infile
* Returns: GPA
* Pre: Infile must be opened
* Post: The gpa is read in from the infile.
*************************************************************/
double read_double(ifstream& infile){
	double gpa;
	infile >> gpa;
	return gpa;
}

/*************************************************************
* Function: read_integer()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: This function reads one integer from the input file
* Input parameters: ifstream infile
* Returns: Number read from infile
* Pre: Infile must be opened
* Post: The integer is read in from the infile.
*************************************************************/
int read_integer(ifstream& infile){
	int num;
	infile >> num;
	return num;
}

/*************************************************************
* Function: read_string()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: This function reads one string from the input file
* Input parameters: ifstream infile
* Returns: idNum
* Pre: Infile must be opened
* Post: The id number is read in as a string from the infile.
*************************************************************/
string read_string(ifstream& infile){
	string idNum;
	infile >> idNum;
	return idNum;
}

/*************************************************************
* Function: store_data_sets()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Accepts 4 output parameter vectors to store all data read from our file, 
and finds the IDs associated with the max and min
* Input parameters: infile, idNums, standings, gpas, ages, maxID, minID
* Returns: the number of records read from file – returns -1 if unable to read all full sets
of data
* Pre: Infile must be opened
* Post: The data from infile is stored in the vectors, maxID and minID are passed by reference
*************************************************************/
int store_data_sets(ifstream& infile, string& idNums, vector<int>& standings, vector<double>& gpas, vector<double>& ages, string& maxID, string& minID){
	int i = 0, standing = 0, numRecords = 0;
	double gpa = 0.0, age = 0.0, minGpa, maxGpa;
	string idNum = ".", trashbin;

	while(!infile.eof()){
		idNum = read_string(infile);
		gpa = read_double(infile);
		if (numRecords == 0) { //initializes max and min
			maxGpa = gpa;
			minGpa = gpa;
		}
		if (gpa > maxGpa){ //finds id number for max
			maxID = idNum;
		} 
		if (gpa < minGpa){
			minID = idNum;
		}
		standing = read_integer(infile);
		age = read_double(infile);
		getline(infile, trashbin);
		
		idNums = idNum;
		standings.push_back(standing);
		gpas.push_back(gpa);
		ages.push_back(age);

		++numRecords;
	}
	if (!(standings.size() == ages.size() && ages.size() == gpas.size())){
		return -1;
	}
	
	return numRecords;
}

/*************************************************************
* Function: calculate_sum()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Finds the sum of any number of values passed as an argument and returns the result.
* Input parameters: vector<double> 
* Returns: sum of all the numbers in the vector
* Pre: vector must be initialized with doubles
* Post: sum is returned
*************************************************************/
double calculate_sum(vector<double> numbers){
	double sum = 0;
	while (numbers.size() > 0){
		sum += numbers.back();
		numbers.pop_back();	
	}

	return sum;
}

/*************************************************************
* Function: calculate_sum()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Finds the sum of any number of values passed as an argument and returns the result.
* Input parameters: vector<int> 
* Returns: sum of all the numbers in the vector
* Pre: vector must be initialized with ints
* Post: sum is returned
*************************************************************/
int calculate_sum(vector<int> numbers){
	int sum = 0;
	while (numbers.size() > 0){
		sum += numbers.back();
		numbers.pop_back();	
	}

	return sum;
}

/*************************************************************
* Function: calculate_mean()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Determines the mean through the calculation sum / number and returns the result. 
* Input parameters: sum and number of records
* Returns: average of sum or -1 if it is 0
* Pre: sum must be found 
* Post: mean is returned
*************************************************************/
double calculate_mean(double sum, int number){
	if ((sum / number) == 0){
		return -1;
	}
	return sum / number;
}

/*************************************************************
* Function: calculate_count_above_mean()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Calculates the count of GPAs greater than the mean GPA
* Input parameters: mean, gpas vector
* Returns: the integer count to the calling function.
* Pre: vector must be filled with gpas and mean must be calculated
* Post: count is returned
*************************************************************/
int calculate_count_above_mean(double mean, vector<double> Gpas){
	int count = 0;
	while (Gpas.size() > 0){
		if (Gpas.back() > mean){
			count++;
		}	
		Gpas.pop_back();	
	}
	return count;
}

/*************************************************************
* Function: calculate_count_below_mean()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Calculates the count of GPAs less than the mean GPA
* Input parameters: mean, gpas vector
* Returns: the integer count to the calling function.
* Pre: vector must be filled with gpas and mean must be calculated
* Post: count is returned
*************************************************************/
int calculate_count_below_mean(double mean, vector<double> Gpas){
int count = 0;
	while (Gpas.size() > 0){
		if (Gpas.back() < mean){
			count++;
		}	
		Gpas.pop_back();	
	}
	return count;
}

/*************************************************************
* Function: calculate_deviation()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: : Determines the individual deviations from the mean for any number
of values and returns the results. The individual deviation may be calculated as
number - mean.
* Input parameters: deviation vector, mean, gpas vector
* Returns: void
* Pre: mean must be calculated, gpas vector must be filled
* Post: deviation vector is filled with doubles
*************************************************************/
void calculate_deviation(vector<double> Gpas, double mean, vector<double>& deviation){
	while (Gpas.size() > 0){ 
		deviation.push_back(Gpas.back() - mean);
		if (deviation.back() < 0){
			deviation.back() *= -1; // makes sure num is positive
		}
		Gpas.pop_back();
	}
}

/*************************************************************
* Function: calculate_variance()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: This function calculates variance for any number of values
* Input parameters: deviation vector, number of records
* Returns: variance
* Pre: deviation vector must be filled with correct values
* Post: variance is returned
*************************************************************/
double calculate_variance(vector<double> deviation, int number){
	double sum = 0.0;
	while (deviation.size() > 0){ 
		sum += pow(deviation.back(), 2);
		deviation.pop_back();
	}
	return sum / number;
}

/*************************************************************
* Function: calculate_standard_deviation()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Calculates standard deviation
* Input parameters: variance
* Returns: standard deviation
* Pre: variance must be calculated
* Post: standard deviation is returned
*************************************************************/
double calculate_standard_deviation(double variance){
	return sqrt(variance);
}

/*************************************************************
* Function: find_max()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Finds the max gpa 
* Input parameters: gpas vector
* Returns: max
* Pre: vector must be filled with gpas
* Post: max is returned
*************************************************************/
double find_max(vector<double> gpas){
	int i;
	double max;
	max = gpas.at(0);
	for (i = 0; i < gpas.size(); ++i){
		if (gpas.at(i) > max){
			max = gpas.at(i);
		}
	}
	return max;
}

/*************************************************************
* Function: find_min()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Finds the min gpa 
* Input parameters: gpas vector
* Returns: min
* Pre: vector must be filled with gpas
* Post: min is returned
*************************************************************/
double find_min(vector<double> gpas){
	int i;
	double min;
	min = gpas.at(0);
	for (i = 0; i < gpas.size(); ++i){
		if (gpas.at(i) < min){
			min = gpas.at(i);
		}
	}
	return min;
}

/*************************************************************
* Function: print_formatted_double()
* Date Created: 12/6/20
* Date Last Modified: 12/6/20
* Description: Prints a double precision number (to the hundredths place) to an output file. The
precision parameter indicates the number of decimal places to be displayed
* Input parameters: outfile, double number, precision
* Returns: void
* Pre: outfile must be opened
* Post: number is written to outfile
*************************************************************/
void print_formatted_double(ofstream& outfile, double number, int precision){
	outfile << fixed << setprecision(precision) << number << endl;

}

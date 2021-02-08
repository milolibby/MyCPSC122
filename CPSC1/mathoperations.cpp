#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int num1;
	int num2;

	cout << "Type any integer" << endl;
	cin >> num1;

	cout << "Type another integer" << endl;
	cin >> num2; /* User is prompted to enter two integers
	and are assigned to num1 and num2 */


	int numSum;  
	int numDifference;
	int numQuotient;
	int numProduct;
	int numRemainder;

	numSum = num1 + num2;
	numDifference = num1 - num2;
	numQuotient = num1 / num2;
	numProduct = num1 * num2;
	numRemainder = num1 % num2; /* Each mathmatical equation between the two integers inputted
	is assigned to its own variable */

	cout << num1 << " + " << num2 << " = " << numSum << endl;
	cout << num1 << " - " << num2 << " = " << numDifference << endl;
	cout << num1 << " / " << num2 << " = " << numQuotient << endl;
	cout << num1 << " * " << num2 << " = " << numProduct << endl;
	cout << "Remainder of " << num1 << " / " << num2 << " = " << numRemainder << endl; /* the results of the above
	calculations are displayed to the user */

	
	

	return 0;
}





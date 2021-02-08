#include <iostream> 
using namespace std;

int getUserHeight();
double convertInchesToCentimeters(int heightInches);
int calculateSnowboardLength(double heightCM);
void displaySnowboardLength(int heightInches, int snowboardLength);

int main()
{
	int heightInches;
	double heightCM;
	double snowboardLength;

	heightInches = getUserHeight();
	heightCM = convertInchesToCentimeters(heightInches);
	snowboardLength = calculateSnowboardLength(heightCM);
	displaySnowboardLength(heightInches, snowboardLength);





	return 0;
}



int getUserHeight(){
	int heightInches;
	int heightFeet;	
	cout << "Enter the height in feet and inches (e.g. 5 4).";
	cin >> heightFeet;
	cin >> heightInches;
	
	heightInches = heightInches + (heightFeet * 12);
	return heightInches;
}

double convertInchesToCentimeters(int heightInches){
	double heightCM;
	heightCM = heightInches * 2.54;
	
	return heightCM;
}

int calculateSnowboardLength(double heightCM){
	int snowboardLength;
	snowboardLength = heightCM * .88;
	
	return snowboardLength;
}

void displaySnowboardLength(int heightInches, int snowboardLength){
	cout << "For a rider of " << heightInches << " inches, a snowboard length of " << snowboardLength << " cms is recommended" << endl;
}




#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	string userName;
	string userFrom;
	
	cout << "What is your name?" << endl;
	//cin >> userName; // reads characters in until it reaches whitespace
	// whitespace: spaces, newlines, tabs
	getline(cin, userName);
	
	
	cout << "Hi there, it is nice to meet you " << userName << "!" << endl; 
	cout << "My name is Chatbot." << endl;
	
	cout << "Where are you from ? " << endl;
	getline(cin, userFrom);
	
	cout << "How lucky, I have heard great things about " << userFrom << "!" <<endl;
	
	int userBirthYear;
	int userAge;
	int chatbotAge;
	int ageCompared; // ageCompared / userAge

	cout << "What year where you born in if you do not mind me asking?" <<endl;
	cin >> userBirthYear;
	userAge = 2020 - userBirthYear;
	chatbotAge = 1; // Chatbot age
	ageCompared = userAge / chatbotAge;
	
	cout << "What a great time to be born in! " << "That means that you will be " << userAge << " at some point this year\n";
	
	cout << "You are " << ageCompared << " times as old as me." << endl;
	cout << "As a newly created bot, I am only " << chatbotAge << " years young!" << endl;

	string dreamCar;
	cout << "Slighty random question, but what is your dream car? " << endl;
	string dummy;
	getline(cin, dummy);	
	getline(cin,dreamCar);

	cout << "No way! I have always wanted a " << dreamCar << ". I have a feeling they are pretty pricy." << endl;
	
	double carPrice = 1.0;
	int loanYears = 0; // Number of years taking out a loan
	double interestRate = 1.0; // Annual (Percent)
	
	cout << "How much does a " << dreamCar << " sell for these days? " << endl;
	cin >> carPrice;
	cout << "Boy I was right, that is expensive!" << endl;

	double gasMileage;
	cout << "What is your ideal MPG for your dream car?" << endl;
	cin >> gasMileage;
	
	if(gasMileage >= 34.1) {
	cout << "That's great! You can save a lot of money on gas, and it is better for the environment. Good on you!\n";
	}

	else {
	cout << "Who cares about the environment anyways these days. Just joking of course :)" << endl;
	}
	
	cout << "If you were to buy the " << dreamCar << ", how many years would you take out a loan for?" << endl;
	cin >> loanYears;
	
	cout << "What kind of interest rate do you think you would get for that beauty?" << endl;
	cin >> interestRate;

	double monthlyPayments; //Car price + interest
	double totalCost; 
	
	
	
	interestRate = (interestRate / 100.0) / 12.0; // convert to decimal / 12 months in a year
	
	monthlyPayments = (interestRate * carPrice) / (1 - pow(1 + interestRate, -(12 * loanYears)));
	totalCost = monthlyPayments * loanYears * 12.0;
	
	cout << fixed << setprecision(2);
	
	cout << "If you did decide to purchase the " << dreamCar << " it would cost you " << monthlyPayments << " per month." 	  << endl;
	cout << "That would bring you to a total of " << totalCost << " all together. Not bad for your dream car.";

	cout << " I say you go for it! I enjoyed chatting, but it is time for me to go. Hopefully you get yourself that " << 		dreamCar << "!" << endl;

	

	
	

 
	
	return 0;
}

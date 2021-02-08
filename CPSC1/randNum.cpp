 #include <iostream>

using namespace std;



int main() {
	int i;
	int n;
	int randNum4;
	int randNum10;

	cout << "Please enter the number of times to roll the dice (4 sides)!" << endl;
	cin >> n;

	
	for (i=1; i <= n; i++){
	randNum4 = rand() % 4 + 1;
	randNum10 = rand() % 10 + 1;
	cout << "You rolled a" << randNum4 << "(out of 4) and a " << randNum10 << "(out of 10)!" << endl;
}
	



	return 0;

}



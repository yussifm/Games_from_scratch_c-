#include <iostream>
//#include <string>

using namespace std;
//using namespace coded;

int main() {

	// Variables 

	// This is not recommended 
	// int age;


	// This is more Recemmended
	int score = 0;
	double distance = 120.0;
	char playAgain = 'y';
	bool shieldsUp = false;

	short lives = 3, aliensKilled = 0;
	long money = 122.3;

	double engineTemp = 333.5; 

	cout << "\nScore: " << score << endl;
	cout << "\nDistance: " << distance << endl;
	cout << "\nPlay Again: " << playAgain << endl;
	cout << "\nLives:" << lives << endl;

	int fuel = 0;

	cout << "\n How much fuel?";
	cin >> fuel;
	cout << "fuel:" << fuel << endl;


	typedef unsigned short int ushort;
	ushort bonus = 10;
	cout << "\n bonus: " << bonus << endl;




	return 0;
}

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//generates a random number from 1-100 using rand()
void function_a() {
	srand((time(NULL)));
	for (int i = 0; i < 100; i++) {
		int random_int = rand() % 100;
		cout << i+1 << ".[" << random_int << "]\n";
	}
}

//generates 100 random numbers from 0-1, otherwise known as a random uniform number 
void function_b() {
	cout << fixed << setprecision(2);
	double min = .25;
	double max = .50;
	for (int i = 0; i < 100; i++) {
		double random_double = min + (max - min) * rand() / RAND_MAX;
		cout << i + 1 << ".[" << random_double << "]\n";
	}
}

//generates 100 random numbers in which 1 is produced with probability of .5, 2 with probability of .2
//otherwise generates a number between 3-4
void function_c() {
	cout << fixed << setprecision(2);
	double min = 3.0;
	double max = 4.0;
	for (int i = 0; i < 100; i++) {
		double random = static_cast<double>(rand()) / RAND_MAX;
		if (random < .5)
			cout << i + 1 << ".[1]\n";
		else if (random < .7)
			cout << i + 1 << ".[2]\n";
		else {
			random = min + (max - min) * rand() / RAND_MAX;
			cout << i + 1 << ".[" << random << "]\n";
		}
	}
}

int main() {
	int option;
	cout << "Enter 0 to quit:\n";
	cout << "Enter 1 to run function a:\n";
	cout << "Enter 2 to run function b:\n";
	cout << "Enter 3 to run function c:\n";
	do {
		cin >> option;
		system("cls");
		if (option == 1)
			function_a();
		else if (option == 2)
			function_b();
		else if (option == 3)
			function_c();

	} while (option != 0);
	return 0;
}


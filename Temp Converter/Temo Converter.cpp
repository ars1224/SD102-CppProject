#include<iostream>
using namespace std;

int main() {

	char unit, unit2;
	double temp;

		cout << "Enter your temperature: ";
		cin >> temp;
	
	while (true) {
		cout << "Enter the temperature scale ( Celsius(C), Fahrenheit(F), Kelvin(K) ): ";
		cin >> unit;

		unit = toupper(unit);

		if (unit != 'C' && unit != 'F' && unit != 'K') {
			cout << "Invalid Input" << endl;
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "Enter the temperature scale you want to convert to (C, F, K): ";
		cin >> unit2;

		unit2 = toupper(unit2);

		if (unit2 != 'C' && unit2 != 'F' && unit2 != 'K') {
			cout << "Invalid Input" << endl;
		}
		else {
			break;
		}
	}

		if (unit == 'c' && unit2 == 'f') {
			
		}
	

	return 0;
}
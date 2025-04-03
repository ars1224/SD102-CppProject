#include <iostream>
using namespace std;

int main() {
    char unit, unit2, choice;
    double temp;

    do{
    cout << "Enter your temperature: ";
    cin >> temp;
    cout << "Enter the temperature scale (Celsius (C), Fahrenheit (F), Kelvin (K)): ";
    cin >> unit;
    unit = toupper(unit);

    if (unit != 'C' && unit != 'F' && unit != 'K') {
        cout << "Invalid input! Please enter C, F, or K." << endl;
        return 1; // Exit the program with an error code
    }

    cout << "Enter the temperature scale you want to convert to (C, F, K): ";
    cin >> unit2;
    unit2 = toupper(unit2);

    if (unit2 != 'C' && unit2 != 'F' && unit2 != 'K') {
        cout << "Invalid input! Please enter C, F, or K." << endl;
        return 1;
    }

    // Conversion logic
    if (unit == 'C') {
        switch (unit2) {
        case 'F': cout << temp * 1.8 + 32 << " Fahrenheit" << endl; break;
        case 'K': cout << temp + 273.15 << " Kelvin" << endl; break;
        case 'C': cout << temp << " Celsius" << endl; break;
        }
    }
    else if (unit == 'F') {
        switch (unit2) {
        case 'C': cout << (temp - 32) / 1.8 << " Celsius" << endl; break;
        case 'K': cout << (temp - 32) / 1.8 + 273.15 << " Kelvin" << endl; break;
        case 'F': cout << temp << " Fahrenheit" << endl; break;
        }
    }
    else if (unit == 'K') {
        switch (unit2) {
        case 'C': cout << temp - 273.15 << " Celsius" << endl; break;
        case 'F': cout << (temp - 273.15) * 1.8 + 32 << " Fahrenheit" << endl; break;
        case 'K': cout << temp << " Kelvin" << endl; break;
        }
    }

    do {
        cout << "Do you want to do another conversion? (Y/N)" << endl;
        cin >> choice;
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Invalid input" << endl;
        }
    } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
}while (choice == 'Y' || choice == 'y');

cout<< "Thank you for using the Temp Converter" << endl;

    return 0;
}

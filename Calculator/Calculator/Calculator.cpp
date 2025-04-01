#include <iostream>
using namespace std;

int main() {
    char choice;
    do {
        double a, b; 
        char op;

        cout << "Calculator App By Jhon Aries Tayao" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << endl;

        while (true) {
            cout << "Enter First Number: ";
            cin >> a;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a valid number.\n";
            }
            else {
                break;
            }
        }

        while (true) {
            cout << "Enter Second Number: ";
            cin >> b;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a valid number.\n";
            }
            else {
                break;
            }
        }

        while (true) {
            cout << "What operand do you want to use? (+ - * /): ";
            cin >> op;

            if (op == '+' || op == '-' || op == '*' || op == '/') {
                break;
            }
            else {
                cout << "Invalid operator! Please enter +, -, *, or /.\n";
            }
        }

        switch (op) {
        case '+':
            cout << "Result: " << (a + b) << endl;
            break;
        case '-':
            cout << "Result: " << (a - b) << endl;
            break;
        case '*':
            cout << "Result: " << (a * b) << endl;
            break;
        case '/':
            if (b != 0)
                cout << "Result: " << (a / b) << endl;
            else
                cout << "Error: Division by zero is not allowed!" << endl;
            break;
        }

        do {
            cout << "Do you want to do another computation? (Y/N)" << endl;
            cin >> choice;
            if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
                cout << "Invalid input" << endl;
            }
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the calculator" << endl;
    return 0;
}

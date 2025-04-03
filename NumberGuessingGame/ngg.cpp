#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed random number generator
    int generatedNumber, userGuess, attempts;
    char playAgain, wantClue;

    cout << "===== Welcome to the Number Guessing Game! =====\n";

    do {
        generatedNumber = rand() % 100 + 1; // Generate a number between 1 and 100
        attempts = 0;
        bool guessedCorrectly = false;

        cout << "\nI have picked a number between 1 and 100.\n";
        cout << "You have 5 tries to guess it correctly.\n";

        while (attempts < 5) {
            cout << "\nAttempt " << (attempts + 1) << " - Enter your guess: ";
            cin >> userGuess;
            attempts++;

            if (userGuess == generatedNumber) {
                cout << "\n?? CONGRATULATIONS! YOU WIN! ??\n";
                cout << "The number was: " << generatedNumber << "\n";
                guessedCorrectly = true;
                break;
            }
            else {
                cout << "Oops! That's wrong.\n";

                if (attempts < 5) {
                    cout << "Do you want a clue? (y/n): ";
                    cin >> wantClue;

                    if (wantClue == 'y' || wantClue == 'Y') {
                        if (userGuess > generatedNumber)
                            cout << "Hint: Try a LOWER number.\n";
                        else
                            cout << "Hint: Try a HIGHER number.\n";
                    }
                }
            }
        }

        if (!guessedCorrectly) {
            cout << "\n? GAME OVER! ?\n";
            cout << "The correct number was: " << generatedNumber << "\n";
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!\n";
    return 0;
}

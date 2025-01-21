#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <limits> // For numeric limits
using namespace std;

class NumberGuessingGame {
public:
    void start() {
        // Seed the random number generator
        srand(static_cast<unsigned int>(time(0)));
        do {
            target_number = rand() % 100 + 1; // Random number between 1 and 100
            cout << "\nWelcome to the Number Guessing Game:)\n";
            cout << "Guess a number between 1 and 100.\n   *****Best of luck***** \n";
            
            playGame(); // Start the game
        } while (playAgain()); // Ask if the player wants to play again

        cout << "Thank you for playing! Goodbye!\n";
    }

private:
    int target_number;

    void playGame() {
        int guess;
        int attempts = 0;
        const int max_attempts = 10;

        while (attempts < max_attempts) {
            cout << "Enter your guess: ";
            cin >> guess;

            // Validate input
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a number between 1 and 100.\n";
                continue;
            }

            if (guess < 1 || guess > 100) {
                cout << "The number must be between 1 and 100.\nPlease try again.\n";
            } else if (guess < target_number) {
                cout << "Too low! Try again.\n";
            } else if (guess > target_number) {
                cout << "Too high! Try again.\n";
            } else {
                cout << "Congratulations! You've guessed the number " << target_number 
                     << " in " << attempts + 1 << " attempts!\n";
                break; // Exit the loop if guessed correctly
            }

            attempts++;
            cout << "Attempts left: " << max_attempts - attempts << "\n";
        }

        if (attempts == max_attempts) {
            cout << "Sorry, you've used all your attempts. The number was " 
                 << target_number << ".\n";
        }
    }

    bool playAgain() {
        char play_again;
        cout << "Do you want to play again? (y/n): ";
        cin >> play_again;

        // Validate input
        while (play_again != 'y' && play_again != 'Y' && 
               play_again != 'n' && play_again != 'N') {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
            cin >> play_again;
        }

        return (play_again == 'y' || play_again == 'Y');
    }
};

int main() {
    NumberGuessingGame game;
    game.start();
    return 0;
}

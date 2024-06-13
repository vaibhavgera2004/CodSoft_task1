// The number guessing game
#include<iostream>
#include<ctime>

using namespace std;

int main() {
    srand(time(0));  // Random number generator with current time
    int n;
    n = (rand() % 100) + 1;  // Generate a random number between 1 and 100
    int guess;
    cout << "Guess a number between 1 and 100: ";
    cin >> guess;
    
    // Continue looping until the user guesses the correct number
    while (guess != n) {
        // Check if the guess is within the valid range (1 to 100)
        if (guess >= 1 && guess <= 100) {
            // Provide feedback based on the user's guess compared to the random number
            if (guess < n && n - guess >= 11) {
                cout << "Too low. Guess again: ";
                cin >> guess;
            }
            else if (guess < n && n - guess <= 10 && n - guess >= 4) {
                cout << "You are low but near. Guess again: ";
                cin >> guess;
            }
            else if (guess < n && n - guess < 4) {
                cout << "You are very close. Guess again: ";
                cin >> guess;
            }
            else if (guess > n && guess - n > 10) {
                cout << "Too high. Guess again: ";
                cin >> guess;
            }
            else if (guess > n && guess - n <= 10 && guess - n >= 4) {
                cout << "You are high but near. Guess again: ";
                cin >> guess;
            }
            else if (guess > n && guess - n < 4) {
                cout << "You are very close. Guess again: ";
                cin >> guess;
            }
        }
        else {
            // Prompt the user to enter a valid guess within the specified range
            cout << "You guessed out of range. Guess again between 1 to 100: ";
            cin >> guess;
        }
    }
    
    // Output messages after the user guesses the correct number
    cout << "You guessed it!" << endl;
    cout << "The number was: " << n << endl;
    cout << "Thanks for playing!" << endl;
    
    return 0;
}

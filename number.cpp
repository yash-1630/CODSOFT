/*NUMBER GUESSING GAME
 Create a program that generates a random number and asks the
 user to guess it. Provide feedback on whether the guess is too
 high or too low until the user guesses the correct number.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); 
    int number = rand() % 100 + 1; 
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high! Try again." << endl;
        } else if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        }
    } while (guess != number);

    return 0;
}

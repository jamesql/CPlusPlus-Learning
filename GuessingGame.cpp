#include <iostream>

using namespace std;

// Decalring variable
int numToGuess;

int main ()
{
    // Seed the random number
    srand ( time(NULL) );
    // Get random number 1-10
    numToGuess = (rand() % 10) + 1;
    // declare guess var here to increase scope
    int guess;
    // Print
    cout << "Guess my number (1-10) : ";
    // While loop to keep guessing
    do {
    // User input
    cin >> guess;
    // Output guess
    cout << "You guessed the number " << guess << endl;
    // Output whether they are higher or lower than the random number
    if (guess > numToGuess) cout << guess << " is higher than the number!" << endl;
        else if (guess < numToGuess) cout << guess << " is lower than the number!" << endl;
    } while (guess != numToGuess);
    // Output congrats message
    cout << "Correct! the right number was " << numToGuess << endl;
    return 0;
}

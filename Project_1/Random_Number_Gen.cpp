#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "\n\t\t\tWelcome to GuessTheNumber game!" << endl;
    cout << "You have to guess a number between 1 and 100. ";
    cout << "You'll have limited choices based on the level you choose. Good Luck!" << endl;

    while (true) {
        cout << "\nEnter the difficulty level: \n";
        cout << "Type 1 for easy!" << endl;
        cout << "Type 2 for medium!" << endl;
        cout << "Type 3 for difficult!" << endl;
        cout << "Type 0 to end the game!\n" << endl;

        int difficultyChoice;
        cout << "Enter the number: ";
        cin >> difficultyChoice;

        srand(static_cast<unsigned int>(time(0)));
        int secretNumber = 1 + (rand() % 100);
        int playerChoice;

        if (difficultyChoice == 1) {
            cout << "\nYou have 10 choices for finding the secret number between 1 and 100.";
            int choicesLeft = 10;
            for (int i = 1; i <= 10; i++) {
                cout << "\n\nEnter your guess: ";
                cin >> playerChoice;

                if (playerChoice == secretNumber) {
                    cout << "Well played! You won, " << playerChoice << " is the secret number" << endl;
                    cout << "\t\t\t Thanks for playing...." << endl;
                    cout << "Play the game again with us!!\n\n" << endl;
                    break;
                } else {
                    cout << "Nope, " << playerChoice << " is not the right number" << endl;
                    if (playerChoice > secretNumber) {
                        cout << "The secret number is smaller than the number you have chosen" << endl;
                    } else {
                        cout << "The secret number is greater than the number you have chosen" << endl;
                    }
                    choicesLeft--;
                    cout << choicesLeft << " choices left." << endl;

                    if (choicesLeft == 0) {
                        cout << "You couldn't find the secret number. It was " << secretNumber << ", You lose!!\n\n";
                        cout << "Play the game again to win!!!\n\n";
                    }
                }
            }
        } else if (difficultyChoice == 2) {
            cout << "\nYou have 7 choices for finding the secret number between 1 and 100.";
            int choicesLeft = 7;
            for (int i = 1; i <= 7; i++) {
                cout << "\n\nEnter your guess: ";
                cin >> playerChoice;

                if (playerChoice == secretNumber) {
                    cout << "Well played! You won, " << playerChoice << " is the secret number" << endl;
                    cout << "\t\t\t Thanks for playing...." << endl;
                    cout << "Play the game again with us!!\n\n" << endl;
                    break;
                } else {
                    cout << "Nope, " << playerChoice << " is not the right number" << endl;
                    if (playerChoice > secretNumber) {
                        cout << "The secret number is smaller than the number you have chosen" << endl;
                    } else {
                        cout << "The secret number is greater than the number you have chosen" << endl;
                    }
                    choicesLeft--;
                    cout << choicesLeft << " choices left." << endl;

                    if (choicesLeft == 0) {
                        cout << "You couldn't find the secret number. It was " << secretNumber << ", You lose!!\n\n";
                        cout << "Play the game again to win!!!\n\n";
                    }
                }
            }
        } else if (difficultyChoice == 3) {
            cout << "\nYou have 5 choices for finding the secret number between 1 and 100.";
            int choicesLeft = 5;
            for (int i = 1; i <= 5; i++) {
                cout << "\n\nEnter your guess: ";
                cin >> playerChoice;

                if (playerChoice == secretNumber) {
                    cout << "Well played! You won, " << playerChoice << " is the secret number" << endl;
                    cout << "\t\t\t Thanks for playing...." << endl;
                    cout << "Play the game again with us!!\n\n" << endl;
                    break;
                } else {
                    cout << "Nope, " << playerChoice << " is not the right number" << endl;
                    if (playerChoice > secretNumber) {
                        cout << "The secret number is smaller than the number you have chosen" << endl;
                    } else {
                        cout << "The secret number is greater than the number you have chosen" << endl;
                    }
                    choicesLeft--;
                    cout << choicesLeft << " choices left." << endl;

                    if (choicesLeft == 0) {
                        cout << "You couldn't find the secret number. It was " << secretNumber << ", You lose!!\n\n";
                        cout << "Play the game again to win!!!\n\n";
                    }
                }
            }
        } else if (difficultyChoice == 0) {
            cout << "Thanks for playing! Goodbye!" << endl;
            break;
        } else {
            cout << "Wrong choice, Enter a valid choice to play the game! (0, 1, 2, 3)" << endl;
        }
    }
    return 0;
}


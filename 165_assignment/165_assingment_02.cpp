#include <bits/stdc++.h>

using namespace std;

// Function prototypes
int getComputerChoice();
int getUserChoice();
void displayChoice(int choice);
void determineOutcome(int user, int computer);

int main() {
    // Seed the random number generator
    srand(time(0));

    int userChoice, computerChoice;
    char playAgain;

    do {
        // Step 1: Get computer's choice
        computerChoice = getComputerChoice();

        // Step 2: Display game menu and get user's choice
        userChoice = getUserChoice();

        if (userChoice == 4) {
            cout << "Please play next time." << endl;
            break;
        }

        // Step 4: Display user's choice
        cout << "You chose: ";
        displayChoice(userChoice);

        // Step 5: Display computer's choice
        cout << "Computer chose: ";
        displayChoice(computerChoice);

        // Step 6: Determine outcome
        determineOutcome(userChoice, computerChoice);

        // Ask user if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}

// Function to get computer's choice
int getComputerChoice() {
    return rand() % 3 + 1; // Generates a random number between 1 and 3
}

// Function to get user's choice
int getUserChoice() {
    int choice;
    cout << "Game Menu" << endl;
    cout << "1) Rock" << endl;
    cout << "2) Paper" << endl;
    cout << "3) Scissors" << endl;
    cout << "4) Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Input validation loop
    while (choice < 1 || choice > 4) {
        cout << "Invalid choice. Please enter a number between 1 and 4: ";
        cin >> choice;
    }

    return choice;
}

// Function to display choice
void displayChoice(int choice) {
    switch (choice) {
        case 1:
            cout << "Rock" << endl;
            break;
        case 2:
            cout << "Paper" << endl;
            break;
        case 3:
            cout << "Scissors" << endl;
            break;
    }
}

// Function to determine the outcome of the game
void determineOutcome(int user, int computer) {
    if (user == computer) {
        cout << "It's a tie!" << endl;
    } else if ((user == 1 && computer == 3) || (user == 2 && computer == 1) || (user == 3 && computer == 2)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

const int MAX_DRINKS = 5;

// Drink structure
struct Drink {
    std::string name;
    double cost;
    int numInMachine;
};

// Function prototypes
void initializeDrinks(Drink drinks[]);
void displayDrinks(const Drink drinks[]);
int selectDrink();
double getAmount();
double calculateChange(double amount, double cost);
void purchaseDrink(Drink drinks[], int selection);

int main() {
    Drink drinkMachine[MAX_DRINKS];
    double totalEarnings = 0.0;
    int choice;

    initializeDrinks(drinkMachine);

    do {
        displayDrinks(drinkMachine);
        choice = selectDrink();

        if (choice >= 1 && choice <= MAX_DRINKS) {
            double amount = getAmount();
            double change = calculateChange(amount, drinkMachine[choice - 1].cost);

            if (change >= 0) {
                std::cout << "Change calculated: $" << std::fixed << std::setprecision(2) << change << std::endl;
                std::cout << "Your change, $" << change << " has just dropped into the Change Dispenser." << std::endl;
                purchaseDrink(drinkMachine, choice);
                totalEarnings += drinkMachine[choice - 1].cost;
            } else {
                std::cout << "Insufficient amount. Please try again." << std::endl;
            }
        } else if (choice != MAX_DRINKS + 1) {
            std::cout << "Invalid selection. Please try again." << std::endl;
        }

    } while (choice != MAX_DRINKS + 1);

    std::cout << "Total earnings: $" << std::fixed << std::setprecision(2) << totalEarnings << std::endl;

    return 0;
}

void initializeDrinks(Drink drinks[]) {
    drinks[0].name = "Cola";
    drinks[0].cost = 0.75;
    drinks[0].numInMachine = 20;

    drinks[1].name = "Root Beer";
    drinks[1].cost = 0.75;
    drinks[1].numInMachine = 20;

    drinks[2].name = "Lemon-Lime";
    drinks[2].cost = 0.75;
    drinks[2].numInMachine = 20;

    drinks[3].name = "Grape Soda";
    drinks[3].cost = 0.80;
    drinks[3].numInMachine = 20;

    drinks[4].name = "Cream Soda";
    drinks[4].cost = 0.80;
    drinks[4].numInMachine = 20;
}

void displayDrinks(const Drink drinks[]) {
    std::cout << "Available drinks:" << std::endl;
    for (int i = 0; i < MAX_DRINKS; i++) {
        std::cout << i + 1 << ") " << drinks[i].name << "\t\t$" << std::fixed << std::setprecision(2) << drinks[i].cost << std::endl;
    }
    std::cout << MAX_DRINKS + 1 << ") Leave the drink machine" << std::endl;
}

int selectDrink() {
    int choice;
    std::cout << "Choose one: ";
    std::cin >> choice;
    return choice;
}

double getAmount() {
    double amount;
    do {
        std::cout << "Enter an amount of money: $";
        std::cin >> amount;
        if (amount < 0.75 || amount > 1.0) {
            std::cout << "Enter at least $0.75 and not more than $1.00." << std::endl;
        }
    } while (amount < 0.75 || amount > 1.0);
    return amount;
}

double calculateChange(double amount, double cost) {
    return amount - cost;
}

void purchaseDrink(Drink drinks[], int selection) {
    int index = selection - 1;
    if (drinks[index].numInMachine > 0) {
        drinks[index].numInMachine--;
        std::cout << "Enjoy your beverage!" << std::endl;
        std::cout << "There are " << drinks[index].numInMachine << " drinks of that type left." << std::endl;
    } else {
        std::cout << "Sorry, that drink is sold out." << std::endl;
    }
}
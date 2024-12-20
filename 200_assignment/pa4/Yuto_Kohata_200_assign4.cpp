#include "Yuto_Kohata_HeartRates.h"
#include <iostream>
#include <string>

// Function to get user input
void getUserInput(std::string& firstName, std::string& lastName, int& month, int& day, int& year) {
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    std::cout << "Enter your last name: ";
    std::cin >> lastName;
    std::cout << "Enter your birth month (1-12): ";
    std::cin >> month;
    std::cout << "Enter your birth day (1-31): ";
    std::cin >> day;
    std::cout << "Enter your birth year: ";
    std::cin >> year;
}

// Function to display user information
void displayUserInfo(const HeartRates& hr) {
    std::cout << "\nUser Information:\n";
    std::cout << "Name: " << hr.getFirstName() << " " << hr.getLastName() << std::endl;
    std::cout << "Date of Birth: " << hr.getBirthMonth() << "/" << hr.getBirthDay() << "/" << hr.getBirthYear() << std::endl;
    std::cout << "Age: " << hr.getAge() << " years\n";
    std::cout << "Maximum Heart Rate: " << hr.getMaximumHeartRate() << " bpm\n";
    std::cout << "Target Heart Rate Range: " << hr.getTargetHeartRate() << " bpm\n";
}

int main() {
    std::string firstName, lastName;
    int birthMonth, birthDay, birthYear;

    getUserInput(firstName, lastName, birthMonth, birthDay, birthYear);

    HeartRates userHeartRates(firstName, lastName, birthMonth, birthDay, birthYear);

    displayUserInfo(userHeartRates);

    return 0;
}
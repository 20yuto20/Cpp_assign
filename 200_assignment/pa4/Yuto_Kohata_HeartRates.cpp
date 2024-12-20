#include "Yuto_Kohata_HeartRates.h"
#include <iostream>
#include <sstream>

// Constructor
HeartRates::HeartRates(std::string first, std::string last, int month, int day, int year)
    : firstName(first), lastName(last), birthMonth(month), birthDay(day), birthYear(year) {}

// Setters
void HeartRates::setFirstName(std::string first) { firstName = first; }
void HeartRates::setLastName(std::string last) { lastName = last; }
void HeartRates::setBirthMonth(int month) { birthMonth = month; }
void HeartRates::setBirthDay(int day) { birthDay = day; }
void HeartRates::setBirthYear(int year) { birthYear = year; }

// Getters
std::string HeartRates::getFirstName() const { return firstName; }
std::string HeartRates::getLastName() const { return lastName; }
int HeartRates::getBirthMonth() const { return birthMonth; }
int HeartRates::getBirthDay() const { return birthDay; }
int HeartRates::getBirthYear() const { return birthYear; }

// Calculate age
int HeartRates::getAge() const {
    int currentMonth, currentDay, currentYear;
    
    std::cout << "Enter current date (MM DD YYYY): ";
    std::cin >> currentMonth >> currentDay >> currentYear;

    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

// Calculate maximum heart rate
int HeartRates::getMaximumHeartRate() const {
    return 220 - getAge();
}

// Calculate target heart rate range
std::string HeartRates::getTargetHeartRate() const {
    int maxRate = getMaximumHeartRate();
    int lowerBound = static_cast<int>(maxRate * 0.5);
    int upperBound = static_cast<int>(maxRate * 0.85);
    
    std::stringstream ss;
    ss << lowerBound << " - " << upperBound;
    return ss.str();
}
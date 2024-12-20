#ifndef HEART_RATES_H
#define HEART_RATES_H

#include <string>

class HeartRates {
private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;

public:
    // Constructor
    HeartRates(std::string first, std::string last, int month, int day, int year);

    // Setters
    void setFirstName(std::string first);
    void setLastName(std::string last);
    void setBirthMonth(int month);
    void setBirthDay(int day);
    void setBirthYear(int year);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    int getBirthMonth() const;
    int getBirthDay() const;
    int getBirthYear() const;

    // Other member functions
    int getAge() const;
    int getMaximumHeartRate() const;
    std::string getTargetHeartRate() const;
};

#endif // HEART_RATES_H
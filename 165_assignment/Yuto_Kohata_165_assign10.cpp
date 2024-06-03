#include <bits/stdc++.h>

using namespace std;

// Function prototypes
void readDataFromFile(char* arr2D, const char* filename); // 1. Function to read data from file
void displayWeatherReport(const char* arr2D); // 2. Function to display weather report
int countWeatherCondition(const char* arr2D, char condition, int startIdx, int endIdx); // 3. Function to count weather condition
int findMonthWithMaxRainyDays(const char* arr2D); // 4. Function to find the month with maximum rainy days

int main() {
    // Create a 2D array and set a pointer to its starting address
    char arr2D[3][30];
    char* ptr = *arr2D; // 5. Pointer points to the start of the 2D array

    // Read data from file
    readDataFromFile(ptr, "RainOrShine.txt"); // 6. Read data from the file

    // Display weather report
    displayWeatherReport(ptr); // 7. Display the weather report

    return 0;
}

void readDataFromFile(char* arr2D, const char* filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        char c;
        int i = 0;
        while (file.get(c)) {
            *(arr2D + i++) = c; // 8. Store each character in the 2D array using pointer arithmetic
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

void displayWeatherReport(const char* arr2D) {
    int monthStart[] = {0, 30, 60};
    int monthEnd[] = {30, 60, 90}; // 9. Ending indices for each month (corrected)

    std::cout << "Weather Report:\n";
    for (int i = 0; i < 3; i++) {
        int rainyDays = countWeatherCondition(arr2D, 'R', monthStart[i], monthEnd[i]);
        int cloudyDays = countWeatherCondition(arr2D, 'C', monthStart[i], monthEnd[i]);
        int sunnyDays = countWeatherCondition(arr2D, 'S', monthStart[i], monthEnd[i]);

        std::cout << (i == 0 ? "June" : i == 1 ? "July" : "August") << ": ";
        std::cout << "Sunny days = " << sunnyDays << ", ";
        std::cout << "Cloudy days = " << cloudyDays << ", ";
        std::cout << "Rainy days = " << rainyDays << std::endl;
    }

    int totalRainyDays = countWeatherCondition(arr2D, 'R', 0, 90);
    int totalCloudyDays = countWeatherCondition(arr2D, 'C', 0, 90);
    int totalSunnyDays = countWeatherCondition(arr2D, 'S', 0, 90);

    std::cout << "\nTotal for 3 months: ";
    std::cout << "Sunny days = " << totalSunnyDays << ", ";
    std::cout << "Cloudy days = " << totalCloudyDays << ", ";
    std::cout << "Rainy days = " << totalRainyDays << std::endl;

    int maxRainyMonth = findMonthWithMaxRainyDays(arr2D);
    std::cout << "\nThe month with the most rainy days was " << (maxRainyMonth == 0 ? "June" : maxRainyMonth == 1 ? "July" : "August") << "." << std::endl;
}

int countWeatherCondition(const char* arr2D, char condition, int startIdx, int endIdx) {
    int count = 0;
    for (int i = startIdx; i < endIdx; i++) { // 10. Iterate from startIdx to endIdx (exclusive)
        if (*(arr2D + i) == condition) {
            count++;
        }
    }
    return count;
}

int findMonthWithMaxRainyDays(const char* arr2D) {
    int monthStart[] = {0, 30, 60};
    int monthEnd[] = {30, 60, 90};
    int maxRainyDays = 0;
    int maxRainyMonth = 0;

    for (int i = 0; i < 3; i++) {
        int rainyDays = countWeatherCondition(arr2D, 'R', monthStart[i], monthEnd[i]);
        if (rainyDays > maxRainyDays) {
            maxRainyDays = rainyDays; // 11. Update the maximum rainy days
            maxRainyMonth = i; // 12. Update the month with maximum rainy days
        }
    }

    return maxRainyMonth;
}
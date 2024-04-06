#include <bits/stdc++.h>

using namespace std;

// Function prototypes
double getTotal(const vector<vector<double>>& array);
double getAverage(const vector<vector<double>>& array);
double getRowTotal(const vector<vector<double>>& array, int row);
double getColumnTotal(const vector<vector<double>>& array, int col);
double getHighestInRow(const vector<vector<double>>& array, int row);
double getLowestInRow(const vector<vector<double>>& array, int row);

int main() {
    // Initialize a 2D array with test data
    vector<vector<double>> testData = {
        {11, 24, 43, 54, 5},
        {5, 53, 11, 72, 8},
        {73, 7, 40, 2, 21}
    };

    // Demonstrate each function
    cout << "Total: " << getTotal(testData) << endl;
    cout << "Average: " << getAverage(testData) << endl;
    cout << "Row 1 Total: " << getRowTotal(testData, 1) << endl;
    cout << "Column 2 Total: " << getColumnTotal(testData, 2) << endl;
    cout << "Highest in Row 0: " << getHighestInRow(testData, 0) << endl;
    cout << "Lowest in Row 2: " << getLowestInRow(testData, 2) << endl;

    return 0;
}

// Calculates the total of all values in the 2D array
double getTotal(const vector<vector<double>>& array) {
    double total = 0;
    for (const auto& row : array) {
        for (double val : row) {
            total += val;
        }
    }
    return total;
}

// Calculates the average of all values in the 2D array
double getAverage(const vector<vector<double>>& array) {
    int count = 0;
    double total = getTotal(array); // Reuse getTotal function to avoid repetition
    for (const auto& row : array) {
        count += row.size();
    }
    return total / count;
}

// Calculates the total of the values in the specified row
double getRowTotal(const vector<vector<double>>& array, int row) {
    double total = 0;
    for (double val : array[row]) {
        total += val;
    }
    return total;
}

// Calculates the total of the values in the specified column
double getColumnTotal(const vector<vector<double>>& array, int col) {
    double total = 0;
    for (const auto& row : array) {
        if (col < row.size()) { // Check to avoid out-of-bounds error
            total += row[col];
        }
    }
    return total;
}

// Finds the highest value in the specified row
double getHighestInRow(const vector<vector<double>>& array, int row) {
    double highest = array[row][0];
    for (double val : array[row]) {
        if (val > highest) highest = val;
    }
    return highest;
}

// Finds the lowest value in the specified row
double getLowestInRow(const vector<vector<double>>& array, int row) {
    double lowest = array[row][0];
    for (double val : array[row]) {
        if (val < lowest) lowest = val;
    }
    return lowest;
}

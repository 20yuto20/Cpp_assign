#include <bits/stdc++.h>

using namespace std;


// Function prototypes
void getJudgeData(double& score);
void calcScore(double scores[]);
double findLowest(double scores[]);
double findHighest(double scores[]);

int main() {
    double scores[5]; // Array to hold scores from 5 judges

    // Get scores from judges
    for (int i = 0; i < 5; ++i) {
        cout << "Enter score for judge #" << (i + 1) << ": ";
        getJudgeData(scores[i]);
    }

    // Calculate and display the average score after dropping the highest and lowest scores
    calcScore(scores);

    return 0;
}

//The function for judgeing if the inputted values are between the given range
void getJudgeData(double& score) {
    cin >> score;
    // Input validation loop
    while (score < 0.0 || score > 10.0) {
        cout << "Invalid score. Please enter a value between 0.0 and 10.0: ";
        cin >> score;
    }
}

//The function for calculating average with dropping the max and min values
void calcScore(double scores[]) {
    double lowest = findLowest(scores);
    double highest = findHighest(scores);
    double sum = 0.0;
    for (int i = 0; i < 5; ++i) {
        sum += scores[i];
    }

    // Subtract the highest and lowest scores then divide by 3 to get the average
    double average = (sum - lowest - highest) / 3.0;

    cout << fixed << setprecision(2);
    cout << "The final score after dropping the highest and lowest scores is: " << average << endl;
}

//The function for finding the smallest value
double findLowest(double scores[]) {
    double lowest = scores[0];
    //The following function is a renewig the values with using the if separating
    for (int i = 1; i < 5; ++i) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}

//The function for finding the largest value
double findHighest(double scores[]) {
    double highest = scores[0];
    for (int i = 1; i < 5; ++i) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

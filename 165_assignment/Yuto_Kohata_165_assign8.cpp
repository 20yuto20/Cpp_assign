#include <bits/stdc++.h>

using namespace std;

// Function prototypes
void readDataFromFile(const string& filename, vector<string>& data);
void displayTeams(const vector<string>& teams);
void displayWinners(const vector<string>& winners); // Declare displayWinners function prototype
string getTeamName();
int countWins(const vector<string>& winners, const string& teamName);

int main() {
    vector<string> teams;
    vector<string> winners;

    // Read data from files into vectors
    readDataFromFile("Teams.txt", teams);
    readDataFromFile("Winners.txt", winners);

    // Display all teams
    displayTeams(teams);

    // Prompt user for a team name
    string teamName = getTeamName();

    // Count and display wins for the entered team
    int wins = countWins(winners, teamName);
    cout << teamName << " have won the World Series " << wins << " times b/w 1903 - 20012." << endl;

    return 0;
}

// Function to read data from file and store it into a vector
void readDataFromFile(const string& filename, vector<string>& data) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        data.push_back(line);
    }
    file.close();
}

// Function to display all teams
void displayTeams(const vector<string>& teams) {
    cout << "Teams:" << endl;
    for (const string& team : teams) {
        cout << team << endl;
    }
    cout << endl;
}

// Function to prompt the user for a team name
string getTeamName() {
    string teamName;
    cout << "Enter the name of a team to check World Series wins: ";
    getline(cin, teamName);
    return teamName;
}

// Function to count how many times the team won the World Series
int countWins(const vector<string>& winners, const string& teamName) {
    int count = 0;
    for (const string& winner : winners) {
        // Convert both the winner and the teamName to lowercase for case-insensitive matching
        string lowercaseWinner = winner;
        string lowercaseTeamName = teamName;
        transform(lowercaseWinner.begin(), lowercaseWinner.end(), lowercaseWinner.begin(), ::tolower);
        transform(lowercaseTeamName.begin(), lowercaseTeamName.end(), lowercaseTeamName.begin(), ::tolower);

        // Check if the team name is a substring of the winner
        if (lowercaseWinner.find(lowercaseTeamName) != string::npos) {
            count++;
        }
    }
    return count;
}



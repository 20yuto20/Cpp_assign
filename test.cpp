#include <bits/stdc++.h>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Function prototypes
bool isMagicSquare(int[][COLS]);
bool checkRange(int[][COLS]);
bool checkUnique(int[][COLS]);
bool checkRowSum(int[][COLS]);
bool checkColSum(int[][COLS]);
bool checkDiagSum(int[][COLS]);

int main() {
    // Initialize two 3x3 grids with random values
    int grid1[ROWS][COLS];
    int grid2[ROWS][COLS];
    srand(time(0)); // Seed for random number generation

    // Fill grid1 with random values
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid1[i][j] = rand() % 9 + 1; // Random value between 1 and 9
        }
    }

    // Fill grid2 with random values
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid2[i][j] = rand() % 9 + 1; // Random value between 1 and 9
        }
    }

    // Display grid1
    cout << "Grid 1:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << grid1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Check if grid1 is a Lo Shu Magic Square
    cout << "Grid 1 is " << (isMagicSquare(grid1) ? "a Lo Shu Magic Square" : "not a Lo Shu Magic Square") << endl;

    // Display grid2
    cout << "Grid 2:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << grid2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Check if grid2 is a Lo Shu Magic Square
    cout << "Grid 2 is " << (isMagicSquare(grid2) ? "a Lo Shu Magic Square" : "not a Lo Shu Magic Square") << endl;

    return 0;
}

// Function to check if a given grid is a Lo Shu Magic Square
bool isMagicSquare(int grid[][COLS]) {
    return checkRange(grid) && checkUnique(grid) && checkRowSum(grid) && checkColSum(grid) && checkDiagSum(grid);
}

// Function to check if all numbers in the grid are within the range 1-9
bool checkRange(int grid[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (grid[i][j] < 1 || grid[i][j] > 9) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if all numbers in the grid are unique
bool checkUnique(int grid[][COLS]) {
    bool seen[10] = {false};
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (seen[grid[i][j]]) {
                return false;
            }
            seen[grid[i][j]] = true;
        }
    }
    return true;
}

// Function to check if the sum of each row in the grid is the same
bool checkRowSum(int grid[][COLS]) {
    int sum = 0;
    for (int j = 0; j < COLS; ++j) {
        sum += grid[0][j];
    }
    for (int i = 1; i < ROWS; ++i) {
        int rowSum = 0;
        for (int j = 0; j < COLS; ++j) {
            rowSum += grid[i][j];
        }
        if (rowSum != sum) {
            return false;
        }
    }
    return true;
}

// Function to check if the sum of each column in the grid is the same
bool checkColSum(int grid[][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; ++i) {
        sum += grid[i][0];
    }
    for (int j = 1; j < COLS; ++j) {
        int colSum = 0;
        for (int i = 0; i < ROWS; ++i) {
            colSum += grid[i][j];
        }
        if (colSum != sum) {
            return false;
        }
    }
    return true;
}

// Function to check if the sum of each diagonal in the grid is the same
bool checkDiagSum(int grid[][COLS]) {
    int sum1 = grid[0][0] + grid[1][1] + grid[2][2];
    int sum2 = grid[0][2] + grid[1][1] + grid[2][0];
    return sum1 == sum2;
}

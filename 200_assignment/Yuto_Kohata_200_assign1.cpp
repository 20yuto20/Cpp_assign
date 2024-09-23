#include <bits/stdc++.h>
using namespace std;

const int COLS = 5;

int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
    // Define the number of rows in the 2D array
	const int ROWS = 4;  
	
    // Initialize a 2D array with test data
	int testArray[ROWS][COLS] =
					{ { 11,   13,  23,  24,  53 },
					{   62,   78,  83,  67, 10 },
					{  11,  19, 17, 42, 13 },
					{  26,  79, 8, 19, 29 } };
    
    // Display the total of all elements in the array
	cout << "The total of the array elements is "
		 << getTotal(testArray, ROWS)
		 << endl;
    
    // Display the average value of all elements in the array
	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;

	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;

	cout << "The total of col 2 is "
		 << getColumnTotal(testArray, 2, ROWS)
		 << endl;
     
	cout << "The highest value in row 2 is "
		 << getHighestInRow(testArray, 2)
		 << endl;

	cout << "The lowest value in row 2 is "
		 << getLowestInRow(testArray, 2)
		 << endl;
        
    system("PAUSE");
	return 0;
}

// This function calculates the total sum of all elements in the 2D array
int getTotal(int array[][COLS], int rows)
{
    int total = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            total += array[i][j];
        }
    }
    return total;
}

// This function calculates the average value of all elements in the 2D array
double getAverage(int array[][COLS], int rows)
{
    int total = getTotal(array, rows);
    return static_cast<double>(total) / (rows * COLS);
}

// This function calculates the sum of all elements in a specific row
int getRowTotal(int array[][COLS], int rowToTotal)
{
    int rowSum = 0;
    for (int j = 0; j < COLS; j++) {
        rowSum += array[rowToTotal][j];
    }
    return rowSum;
}

// This function calculates the sum of all elements in a specific column
int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
    int colSum = 0;
    for (int i = 0; i < rows; i++) {
        colSum += array[i][colToTotal];
    }
    return colSum;
}

// This function finds the highest value in a specific row
int getHighestInRow(int array[][COLS], int rowToSearch)
{
    int highest = array[rowToSearch][0];
    for (int j = 1; j < COLS; j++) {
        if (array[rowToSearch][j] > highest) {
            highest = array[rowToSearch][j];
        }
    }
    return highest;
}

// This function finds the lowest value in a specific row
int getLowestInRow(int array[][COLS], int rowToSearch)
{
    int lowest = array[rowToSearch][0];
    for (int j = 1; j < COLS; j++) {
        if (array[rowToSearch][j] < lowest) {
            lowest = array[rowToSearch][j];
        }
    }
    return lowest;
}
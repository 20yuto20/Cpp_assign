#include <bits/stdc++.h>

using namespace std;

int getMode(int*, int); // Function declaration for calculating mode
int* makeArray(int); // Function declaration for creating an array

// main has been completed for you

int main()
{	
    const int SIZE = 10; // Constant defining the size of the array
    int test[SIZE] = {7, 5, 1, 9, 2, 8, 4, 6, 3, 5}; // Test array initialized with values
	int mode; // Variable to store the mode

	mode = getMode(test, SIZE); // Call to getMode function to find mode
   
	if (mode == -1)
		cout << "The test set has no mode.\n"; // Output when no mode is found
	else
		cout << "\nThe mode of the test set is: " 
		     << mode << endl; // Output the mode value

    system("PAUSE"); // Pause the system before closing the console window
	return 0; // Indication of successful program execution
}

// Function to calculate the mode of an array
int getMode(int* array, int size) {
    // Dynamically allocate memory for the frequencies array
    int* frequencies = makeArray(size);

    // Initialize all elements of the frequencies array to 0
    for (int i = 0; i < size; i++) {
        *(frequencies + i) = 0;
    }

    // Count the occurrence of each value
    for (int i = 0; i < size; i++) {
        *(frequencies + *(array + i)) += 1;
    }

    // Find the maximum frequency
    int maxFrequency = 0;
    for (int i = 0; i < size; i++) {
        if (*(frequencies + i) > maxFrequency) {
            maxFrequency = *(frequencies + i);
        }
    }

    // If no value appears more than twice, return -1 indicating no mode
    if (maxFrequency <= 1) {
        delete[] frequencies;
        return -1;
    }

    // Find the first value with maximum frequency as the mode
    int mode;
    for (int i = 0; i < size; i++) {
        if (*(frequencies + i) == maxFrequency) {
            mode = i;
            break;
        }
    }

    delete[] frequencies; // Free the dynamically allocated memory
    return mode; // Return the mode
}

// Function to dynamically allocate an array
int* makeArray(int size)
{
	return new int[size];
}

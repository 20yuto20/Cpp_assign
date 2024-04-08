#include <bits/stdc++.h>

using namespace std;

// Function to read data from a file and store it in a vector
vector<string> getVector(const string& filename) {
    vector<string> data;
    ifstream file(filename);
    string name;
    // Read names from the file and push them into the vector
    while (file >> name) {
        data.push_back(name);
    }
    file.close();
    return data;
}

// Function to prompt the user to enter a name
string getName(const string& type) {
    string name;
    // Prompt the user to enter a name or 'N' to skip
    cout << "Enter a " << type << " name, or N if you do not wish to enter a " << type << " name: ";
    cin >> name;
    // Check if the user chose not to enter a name
    if (name == "N") {
        cout << "You chose not to enter a " << type << " name." << endl;
        return "";
    }
    return name;
}

// Function to perform selection sort on a vector of names
void selectionSort(vector<string>& names) {
    int n = names.size();
    // Perform selection sort
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (names[j] < names[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(names[i], names[minIndex]);
        }
    }
}

// Function to search for a name in a sorted vector
bool search(const string& name, const vector<string>& names) {
    return binary_search(names.begin(), names.end(), name);
}

// Function to display the result of name popularity
void displayResult(const string& type, const string& name, bool found) {
    cout << "The " << type << " name '" << name << "' is ";
    // Check if the name is found in the vector
    if (found) {
        cout << "popular." << endl;
    } else {
        cout << "not popular." << endl;
    }
}

// Function to write the contents of a vector to a file
void writeToFile(const string& filename, const vector<string>& data) {
    ofstream file(filename);
    if (file.is_open()) {
        // Write names to the file
        for (const string& name : data) {
            file << name << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

// Function to reverse the order of elements in a vector
void reverseVector(vector<string>& names) {
    int n = names.size();
    // Reverse the vector in-place
    for (int i = 0; i < n / 2; ++i) {
        swap(names[i], names[n - i - 1]);
    }
}

int main() {
    string boyName, girlName;
    bool boyNameFound, girlNameFound;
    
    // Get a boy's name and a girl's name from the user
    boyName = getName("boy's");
    girlName = getName("girl's");
    
    // Exit the program if no names are entered
    if (boyName == "" && girlName == "") {
        return 0;
    }
    
    // Get vectors of boy and girl names from files
    vector<string> boyNames(getVector("BoyNames.txt"));
    vector<string> girlNames(getVector("GirlNames.txt"));
    
    // Sort the vectors of names
    selectionSort(boyNames);
    selectionSort(girlNames);
    
    // Search for the entered boy's name and display the result
    if (boyName != "") {
        boyNameFound = search(boyName, boyNames);
        displayResult("boy's", boyName, boyNameFound);
    }
    
    // Search for the entered girl's name and display the result
    if (girlName != "") {
        girlNameFound = search(girlName, girlNames);
        displayResult("girl's", girlName, girlNameFound);
    }
    
    // Write the sorted boy and girl names to files in ascending order
    writeToFile("Boynames_asc.txt", boyNames);
    writeToFile("Girlnames_asc.txt", girlNames);
    
    // Reverse the vectors of names
    reverseVector(boyNames);
    reverseVector(girlNames);
    
    // Write the sorted boy and girl names to files in descending order
    writeToFile("Boynames_desc.txt", boyNames);
    writeToFile("Girlnames_desc.txt", girlNames);
    
    cout << endl;
    system("PAUSE");
    
    return 0;
}

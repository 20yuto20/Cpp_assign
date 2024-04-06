#include <bits/stdc++.h>

using namespace std;

// Function prototypes
void getStudentAnswers(vector<char>& studentAnswers); // Function prototype for getting student answers
void gradeTest(const vector<char>& answerKey, const vector<char>& studentAnswers); // Function prototype for grading the test

int main() {
    const vector<char> answerKey = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', // Constant vector storing the answer key
                                    'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    vector<char> studentAnswers(20); // Vector to store student answers
    
    getStudentAnswers(studentAnswers); // Call function to get student answers
    gradeTest(answerKey, studentAnswers); // Call function to grade the test

    return 0;
}

void getStudentAnswers(vector<char>& studentAnswers) {
    cout << "Enter the student's answers for each of the 20 questions (A, B, C, D):" << endl;
    for (int i = 0; i < 20; ++i) {
        cout << "Question " << (i + 1) << ": ";
        cin >> studentAnswers[i];
        studentAnswers[i] = toupper(studentAnswers[i]); // Convert to uppercase to standardize
        
        // Input validation: Only accept A, B, C, or D
        while (studentAnswers[i] != 'A' && studentAnswers[i] != 'B' && studentAnswers[i] != 'C' && studentAnswers[i] != 'D') {
            cout << "Invalid input. Please enter A, B, C, or D: ";
            cin >> studentAnswers[i];
            studentAnswers[i] = toupper(studentAnswers[i]); // Convert to uppercase again after new input
        }
    }
}

void gradeTest(const vector<char>& answerKey, const vector<char>& studentAnswers) {
    int correctAnswers = 0;
    vector<int> incorrectQuestions; // Vector to store numbers of incorrectly answered questions
    
    for (int i = 0; i < 20; ++i) {
        if (answerKey[i] == studentAnswers[i]) {
            ++correctAnswers;
        } else {
            incorrectQuestions.push_back(i + 1); // Store incorrect question numbers
        }
    }
    
    // Determine if the student passed or failed
    cout << "\nThe student " << (correctAnswers >= 15 ? "passed" : "failed") << " the exam." << endl;
    
    // Display the total number of correctly and incorrectly answered questions
    cout << "Correct answers: " << correctAnswers << endl;
    cout << "Incorrect answers: " << 20 - correctAnswers << endl;
    
    // Display the question numbers of the incorrectly answered questions, if any
    if (!incorrectQuestions.empty()) {
        cout << "Questions answered incorrectly: ";
        for (int q : incorrectQuestions) {
            cout << q << " ";
        }
        cout << endl;
    }
}

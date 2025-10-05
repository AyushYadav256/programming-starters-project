// Author: Ayush Yadav
// GitHub: https://github.com/AyushYadav256
// Description: Student Record Management System using file handling

#include <iostream>      // For input/output operations
#include <fstream>       // For file handling (ifstream, ofstream)
#include <string>        // For using string data type
using namespace std;     // Avoids prefixing std:: everywhere

// Define a structure to hold student data
struct Student {
    int roll;            // Roll number of the student
    string name;         // Name of the student
    float marks;         // Marks obtained
};

// Function to add a new student record to the file
void addStudent() {
    Student s;                               // Create a Student object
    ofstream out("students.txt", ios::app);  // Open file in append mode

    cout << "Enter Roll No: ";
    cin >> s.roll;                           // Input roll number

    cout << "Enter Name: ";
    cin.ignore();                            // Clear input buffer before getline
    getline(cin, s.name);                    // Input full name

    cout << "Enter Marks: ";
    cin >> s.marks;                          // Input marks

    // Write student data to file in space-separated format
    out << s.roll << " " << s.name << " " << s.marks << endl;
    out.close();                             // Close the file

    cout << "✅ Student added successfully.\n";
}

// Function to display all student records from the file
void displayStudents() {
    Student s;                               // Create a Student object
    ifstream in("students.txt");             // Open file for reading

    cout << "\n📋 Student Records:\n";
    // Read each student record and display it
    while (in >> s.roll >> s.name >> s.marks) {
        cout << "Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << endl;
    }

    in.close();                              // Close the file
}

// Function to search for a student by roll number
void searchStudent() {
    int roll;                                // Roll number to search
    Student s;                               // Create a Student object
    bool found = false;                      // Flag to track if student is found

    ifstream in("students.txt");             // Open file for reading

    cout << "Enter Roll No to search: ";
    cin >> roll;                             // Input roll number to search

    // Read each record and check if roll matches
    while (in >> s.roll >> s.name >> s.marks) {
        if (s.roll == roll) {
            cout << "✅ Found: " << s.name << " with " << s.marks << " marks.\n";
            found = true;
            break;                           // Exit loop once found
        }
    }

    if (!found)                              // If not found, show message
        cout << "❌ Student not found.\n";

    in.close();                              // Close the file
}

// Main function to drive the menu-based system
int main() {
    int choice;                              // User's menu choice

    do {
        // Display menu options
        cout << "\n🎓 Student Record System\n";
        cout << "1. Add Student\n2. Display All\n3. Search by Roll No\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;                       // Input user's choice

        // Perform action based on choice
        switch (choice) {
            case 1: addStudent(); break;     // Add student
            case 2: displayStudents(); break;// Display all records
            case 3: searchStudent(); break;  // Search by roll number
            case 4: cout << "👋 Exiting...\n"; break; // Exit
            default: cout << "❌ Invalid choice.\n";  // Handle invalid input
        }
    } while (choice != 4);                   // Repeat until user chooses to exit

    return 0;                                // End of program
}

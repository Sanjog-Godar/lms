#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> // For system("cls")

using namespace std;
// Function to register user
void registerUser() {
    string username, password;
    cout << "=== Registration Page ===" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Save username and password to a file
    ofstream file("userdata.txt",ios::app);
    if (file.is_open()) {
        file << username << endl;
        file << password << endl;
        file.close();
        cout << "Registration successful! Press Enter to continue...";
        cin.ignore();
        cin.get(); // Wait for user to press Enter
        system("cls"); // Clear the console
    } else {
        cerr << "Error: Unable to save registration details." << endl;
        exit(1);
    }
}

// Function to login user
bool loginUser() {
    string username, password, storedUsername, storedPassword;

    // Read the stored username and password from file
    ifstream file("userdata.txt");
    if (file.is_open()) {
        getline(file, storedUsername);
        getline(file, storedPassword);
        file.close();
    } else {
        cerr << "Error: Unable to read user data." << endl;
        exit(1);
    }

    cout << "=== Login Page ===" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Check if input matches stored credentials
    if (username == storedUsername && password == storedPassword) {
        return true;
    } else {
        return false;
    }
}

// Main page after successful login
void mainPage() {
    cout << "=== Main Page ===" << endl;
    cout << "Welcome to the main page! You have successfully logged in." << endl;
}

int main() {
    // Registration process
    registerUser();

    // Login process
    if (loginUser()) {
        system("cls"); // Clear the console
        mainPage();
    } else {
        cout << "Invalid username or password. Try again!" << endl;
    }

    return 0;
}

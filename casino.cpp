#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> // For system("cls")
#include <cstdlib>  // this library is for generating random number.
using namespace std;
int current_balance = 0;
bool has_entered_balance = false;

// Function to register user
void registerUser()
{
    string username, password;
    cout << "=== Registration Page ===" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Save username and password to a file on a single line
    ofstream file("userdata.txt", ios::app); // Open in append mode
    if (file.is_open())
    {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful! Press Enter to continue...";
        cin.ignore();
        cin.get();     // Wait for user to press Enter
        system("cls"); // Clear the console
    }
    else
    {
        cerr << "Error: Unable to save registration details." << endl;
        exit(1);
    }
}

// Function to login user
bool loginUser()
{
    string username, password, storedUsername, storedPassword;
    cout << "=== Login Page ===" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Read the stored username and password from file
    ifstream file("userdata.txt");
    if (file.is_open())
    {
        while (file >> storedUsername >> storedPassword)
        { // Read username and password from a single line
            if (username == storedUsername && password == storedPassword)
            {
                file.close();
                return true; // Match found
            }
        }
        file.close();
    }
    else
    {
        cerr << "Error: Unable to read user data." << endl;
        exit(1);
    }

    return false; // No match found
}
string getUsernameFromFile()
{
    string username;
    ifstream file("userdata.txt");
    if (file.is_open())
    {
        // Read the first username from the file (assuming it's on the first line)
        file >> username;
        file.close();
    }
    else
    {
        cerr << "Error: Unable to open file." << endl;
    }
    return username;
}
void rules()
{
    cout << "1. The player will choose a number between 1-10\n";
    cout << "2. If the number choosen by the player is winning then the player will get 10x the money bet\n";
    cout << "3. If user fails to make a correct\n";
    cout << "4. User can stop playing anytime he wants" << endl;
    cout << "Press Enter to go back to Main Menu...\t" << endl;
    cin.ignore();
    cin.get();
}
bool amount_check(int bet_amount)
{
    if (bet_amount <= current_balance)
    {
        return true; // Bet amount is valid
    }
    else
    {
        cout << "Bet amount can't be greater than your current balance. Please try again.\n";
        return false; // Invalid bet amount
    }
}

int play()
{
    int bet_amount, lucky_number, winning_number;
    char response;

    if (!has_entered_balance)
    {
        cout << "Enter the balance you have: ";
        cin >> current_balance;
        has_entered_balance = true;
    }
    cout << "Successfully deposited the sum of " << current_balance << endl;

    while (true)
    {
        cout << "----------------------- Balance: " << current_balance << " -----------------------\n";

        do
        {
            cout << "Enter the amount you want to bet: ";
            cin >> bet_amount;
        } while (!amount_check(bet_amount));

        cout << "Enter a number (1-9) as your lucky number: ";
        cin >> lucky_number;

        // Generate winning number
        winning_number = rand() % 10;
        cout << "Winning number is " << winning_number << endl;

        // Check the result
        if (lucky_number == winning_number)
        {
            current_balance += bet_amount * 10;
            cout << "Congrats!!! You won! Your balance increased to " << current_balance << endl;
        }
        else
        {
            current_balance -= bet_amount;
            cout << "Sorry, you lost. Your current balance is " << current_balance << endl;
        }

        // Ask if the user wants to play again
        if (current_balance <= 0)
        {
            cout << "You have run out of balance. Game over!" << endl;
            break;
        }

        cout << "Do you want to play more (Y/y for Yes and N/n for No)? ";
        cin >> response;
        if (response == 'N' || response == 'n')
        {
            break;
        }

        system("cls"); // Clear the console for the next round
    }

    return 0;
}

// Main page after successful login
void mainPage()
{
    int number;
    string username = getUsernameFromFile();
    while (true)
    {
        system("cls");
        cout << "\t\t\t=== Main Page ===" << endl;
        cout << "Welcome\t" << username << endl;
        cout << "--------------------Casino Game By Sanjog--------------------\n";
        cout << "1. Play Now\n";
        cout << "2. Rules\t";
        cin >> number;
        if (number == 1)
        {
            play();
        }
        else if (number == 2)
        {
            system("cls");
            rules();
        }
    }
}

int main()
{
    int choice;
    system("cls");
    cout << "=== Welcome ===" << endl;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;
    system("cls");

    switch (choice)
    {
    case 1:
        registerUser();
        break;

    case 2:
        if (loginUser())
        {
            system("cls"); // Clear the consolex
            mainPage();
        }
        else
        {
            cout << "Invalid username or password. Try again!" << endl;
        }
        break;
    default:
        cout << "Invalid choice. Exiting..." << endl;
    }

    return 0;
}

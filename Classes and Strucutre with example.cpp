#include <iostream>
using namespace std;

// Structure: Groups basic data without methods
struct PersonStruct {
    string name;
    int age;
};

// Class: Groups data with methods for more functionality
class PersonClass {
private:
    string name;
    int age;

public:
    // Constructor to initialize the person's details
    PersonClass(string personName, int personAge) : name(personName), age(personAge) {}

    // Method to display the person's details
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Using Structure
    PersonStruct person1 = {"Alice", 25};
    cout << "Using Structure:\n";
    cout << "Name: " << person1.name << ", Age: " << person1.age << endl;

    // Using Class
    PersonClass person2("Bob", 30);
    cout << "Using Class:\n";
    person2.displayInfo();

    return 0;
}

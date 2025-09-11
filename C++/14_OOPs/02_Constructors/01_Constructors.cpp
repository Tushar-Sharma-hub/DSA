// A constructor is a special member function of a class that is automatically called when an object is created.
// It is used to initialize objects.
// Types of Constructors in C++
// Default Constructor
// Parameterized Constructor
// Copy Constructor
#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;

public:
    // Default constructor
    Student() {
        roll = 0;
        name = "Unknown";
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Student(int r, string n) {
        roll = r;
        name = n;
        cout << "Parameterized constructor called" << endl;
    }

    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }
};

int main() {
    Student s1;                 // Calls default constructor
    Student s2(1, "Tushar");    // Calls parameterized constructor

    s1.display();
    s2.display();

    return 0;
}

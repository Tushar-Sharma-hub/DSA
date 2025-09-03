//Destructor cleans up when an object dies.
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

    // Destructor
    ~Student() {
        cout << "Destructor called for Roll: " << roll << ", Name: " << name << endl;
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

    // Destructor will be called automatically when objects go out of scope
    // Notice destructors are called in reverse order of object creation.
    return 0;
}

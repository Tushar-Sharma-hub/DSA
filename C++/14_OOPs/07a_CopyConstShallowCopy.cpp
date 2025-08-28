//Shallow copy.
#include <iostream>
using namespace std;

class Student {
    int roll;
public:
    // Parameterized constructor
    Student(int r) {
        roll = r;
        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    Student(const Student &s) {
        roll = s.roll;
        cout << "Copy constructor called" << endl;
    }

    void display() {
        cout << "Roll: " << roll << endl;
    }
};

int main() {
    Student s1(10);    // Calls parameterized constructor
    Student s2(s1);    // Calls copy constructor
    s2.display();
    return 0;
}

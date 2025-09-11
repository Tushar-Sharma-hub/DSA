//Deep copy
#include <iostream>
using namespace std;

class Student {
    int *roll;
public:
    // Parameterized constructor
    Student(int r) {
        roll = new int(r);
        cout << "Parameterized constructor called" << endl;
    }

    // Deep Copy Constructor (allocates new memory)
    Student(const Student &s) {
        roll = new int(*s.roll);  //new memory allocated
        cout << "Deep Copy constructor called" << endl;
    }

    void display() {
        cout << "Roll: " << *roll << " (Address: " << roll << ")" << endl;
    }

    // Destructor
    ~Student() {
        delete roll;
        cout << "Destructor called" << endl;
    }
};

int main() {
    Student s1(10);
    Student s2(s1);   // Deep copy (separate memory)
    s1.display();
    s2.display();

    return 0;
}

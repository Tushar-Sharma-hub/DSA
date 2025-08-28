#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;
public:
    static int count;  // declaration of static member

    Student(int r, string n) {
        roll = r;
        name = n;
        count++;   // increase student count
    }

    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }
};

// definition of static member (must be outside class)
int Student::count = 0;

int main() {
    Student s1(1, "Tushar");
    Student s2(2, "Vishal");

    s1.display();
    s2.display();

    cout << "Total Students: " << Student::count << endl; // accessed via class name
    return 0;
}

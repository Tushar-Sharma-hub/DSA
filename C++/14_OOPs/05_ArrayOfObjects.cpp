// Array of Objects.
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    float marks;

    void setData(string n, int a, float m) {
        name = n;
        age = a;
        marks = m;
    }

    void display() {
        cout << "Name: " << name 
             << ", Age: " << age 
             << ", Marks: " << marks << endl;
    }
};

int main() {
    Student arr[3];
    arr[0].setData("Tushar", 19, 85.5);
    arr[1].setData("Oggy", 20, 90.0);
    arr[2].setData("Sharma", 18, 78.2);
    for(int i=0; i<3; i++) {
        arr[i].display();
    }
    return 0;
}

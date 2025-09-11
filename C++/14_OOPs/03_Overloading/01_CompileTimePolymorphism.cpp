// Polymorphism allows the same function or operator name to behave differently based on the context.
// It’s mainly used to make code more flexible and reusable.
// Types of Polymorphism.
// There are two major types:
// Compile-time polymorphism → Function/Operator overloading
// Run-time polymorphism → Virtual functions (overriding)

#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;      // calls int version
    cout << m.add(2.5, 3.5) << endl;  // calls double version
}
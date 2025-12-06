// What is the Diamond Problem?
// Imagine a situation:
// A is the base class.
// B and C both inherit from A.
// D inherits from both B and C.
// Now, D indirectly inherits from A twice — once via B and once via C.
// This causes ambiguity when accessing members of A.
#include <iostream>
using namespace std;

class A {
public:
    int value;
    A() { value = 10; }
};

class B : virtual public A { }; //without virtual you can't directly access value inside class u have to use B::value;
class C : virtual public A { };

class D : public B, public C {
public:
    void show() {
        cout << "Single value = " << value << endl; //using virtual you can direct access value,else you have to use B::value or C::value to access.
    }
};

int main() {
    D obj;
    obj.show();
    return 0;
}

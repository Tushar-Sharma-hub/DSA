// 3. Multi-level Inheritance

//  When a class is derived from another derived class (a chain of inheritance).
#include <iostream>
using namespace std;

class LivingBeing {
public:
    void breathe() {
        cout << "Living being breathes." << endl;
    }
};

class Animal : public LivingBeing {
public:
    void eat() {
        cout << "Animal eats food." << endl;
    }
};

class Dog : public Animal {   // Multi-level Inheritance
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

int main() {
    Dog d;
    d.breathe();
    d.eat();
    d.bark();
    return 0;
}
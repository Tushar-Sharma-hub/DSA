// 5. Hybrid Inheritance

//  A combination of two or more types of inheritance (e.g., multiple + hierarchical).
//  In C++, hybrid inheritance can cause ambiguity (diamond problem). Virtual inheritance is used to solve it.
#include <iostream>
using namespace std;

class LivingBeing {
public:
    void breathe() {
        cout << "Living being breathes." << endl;
    }
};

class Animal : virtual public LivingBeing {
public:
    void eat() {
        cout << "Animal eats." << endl;
    }
};

class Human : virtual public LivingBeing {
public:
    void think() {
        cout << "Human thinks." << endl;
    }
};

class SuperHuman : public Animal, public Human {  // Hybrid Inheritance
public:
    void power() {
        cout << "SuperHuman has special powers." << endl;
    }
};

int main() {
    SuperHuman sh;
    sh.breathe();  // No ambiguity because of virtual inheritance
    sh.eat();
    sh.think();
    sh.power();
    return 0;
}

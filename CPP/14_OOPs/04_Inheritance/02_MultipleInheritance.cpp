// 2. Multiple Inheritance

//  When a class is derived from more than one base class
#include <iostream>
using namespace std;

class Engine {
public:
    void startEngine() {
        cout << "Engine started." << endl;
    }
};

class Wheels {
public:
    void rotate() {
        cout << "Wheels are rotating." << endl;
    }
};

class Car : public Engine, public Wheels {   // Multiple Inheritance
public:
    void drive() {
        cout << "Car is driving." << endl;
    }
};

int main() {
    Car c;
    c.startEngine();
    c.rotate();
    c.drive();
    return 0;
}

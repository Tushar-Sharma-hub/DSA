#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {  // virtual function
        cout << "Base show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived show()" << endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show();  // Output: Derived show() (runtime binding)
    return 0;
}
// If show() were not virtual, the output would be Base show(), because the pointer type is Base*.
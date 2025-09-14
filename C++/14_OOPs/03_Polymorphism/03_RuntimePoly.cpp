#include <iostream>
using namespace std;

class Base {
public:
    void show() {   // no virtual
        cout << "[Base] show() (non-virtual)" << endl;
    }

    virtual void vshow() { // virtual function
        cout << "[Base] vshow() (virtual)" << endl;
    }
};

class Derived : public Base {
public:
    void show() {   // hides Base::show()
        cout << "[Derived] show() (non-virtual)" << endl;
    }

    void vshow() override { // overrides Base::vshow()
        cout << "[Derived] vshow() (virtual)" << endl;
    }
};

int main() {
    Derived d;

    cout << "---- Direct calls ----" << endl;
    d.show();        // Derived version
    d.Base::show();  // Base version (scope resolution)

    d.vshow();        // Derived version
    d.Base::vshow();  // Base version (scope resolution)

    cout << "\n---- Using Base pointer (no virtual) ----" << endl;
    Base* bptr = &d;
    bptr->show();    // Base version ❌ (static binding, no runtime polymorphism)

    cout << "\n---- Using Base pointer (with virtual) ----" << endl;
    bptr->vshow();   // Derived version ✅ (runtime polymorphism)

    return 0;
}

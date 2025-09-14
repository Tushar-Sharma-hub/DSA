#include <iostream>
using namespace std;

class Base {
public:
    int pub = 1;
protected:
    int prot = 2;
private:
    int priv = 3;
};

// Public Inheritance
class DerivedPublic : public Base {
public:
    void show() {
        cout << "Public Inheritance:" << endl;
        cout << "Public = " << pub << endl;      // Accessible
        cout << "Protected = " << prot << endl; // Accessible
        // cout << priv; // ❌ Not accessible
    }
};

// Protected Inheritance
class DerivedProtected : protected Base {
public:
    void show() {
        cout << "Protected Inheritance:" << endl;
        cout << "Public becomes Protected = " << pub << endl;
        cout << "Protected = " << prot << endl;
        // cout << priv; // ❌ Not accessible
    }
};

// Private Inheritance
class DerivedPrivate : private Base {
public:
    void show() {
        cout << "Private Inheritance:" << endl;
        cout << "Public becomes Private = " << pub << endl;
        cout << "Protected becomes Private = " << prot << endl;
        // cout << priv; // ❌ Not accessible
    }
};

int main() {
    DerivedPublic d1;
    d1.show();
    cout << d1.pub << endl; // ✅ Accessible (public stays public)

    DerivedProtected d2;
    d2.show();
    // cout << d2.pub; // ❌ Not accessible (became protected)

    DerivedPrivate d3;
    d3.show();
    // cout << d3.pub; // ❌ Not accessible (became private)

    return 0;
}

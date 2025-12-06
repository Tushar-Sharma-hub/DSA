#include <iostream>
using namespace std;

class Outer {
public:
    int x = 10;

    // Nested class
    class Inner {
    public:
        void display() {
            cout << "Hello from Inner class!" << endl;
        }
    };

    void outerFunction() {
        cout << "Hello from Outer class!" << endl;
    }
};

int main() {
    Outer outerObj;
    outerObj.outerFunction();

    // Creating object of nested class
    Outer::Inner innerObj;
    innerObj.display();

    return 0;
}

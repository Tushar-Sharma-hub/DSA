#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // pure virtual
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    Shape* s1 = new Circle();
    Shape* s2 = new Square();

    s1->draw();  // Output: Drawing Circle
    s2->draw();  // Output: Drawing Square

    // Shape obj; // ❌ Error: cannot instantiate abstract class
}
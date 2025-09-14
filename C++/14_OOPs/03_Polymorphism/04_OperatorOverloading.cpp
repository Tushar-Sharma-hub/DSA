#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Operator overloading for +
    Complex operator+(Complex C) {
        Complex temp;
        temp.real=real+C.real;
        temp.imag=imag+C.imag;
        return temp;
    }

    // Display function
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2; // uses overloaded +
    c3.display(); // Output: 4 + 6i
    return 0;
}

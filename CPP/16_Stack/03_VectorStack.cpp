#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    void push(int x) {
        v.push_back(x);
    }

    void pop() {
        if (v.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        v.pop_back();
    }

    int top() {
        if (v.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return v.back();
    }

    bool isEmpty() {
        return v.empty();
    }

    int size() {
        return v.size();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    return 0;
}

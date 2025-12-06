#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
    Node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (topNode == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == NULL;
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

    s.pop();
    s.pop();
    s.pop();   // Underflow check

    return 0;
}

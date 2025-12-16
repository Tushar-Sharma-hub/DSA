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

    void display() {
        if (topNode == NULL) {
            cout << "Stack is Empty\n";
            return;
        }

        Node* temp = topNode;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top: " << s.top() << endl;

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop();

    return 0;
}

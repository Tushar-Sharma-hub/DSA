//Implementation of Deque using DLL.
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x){
        data = x;
        prev = next = NULL;
    }
};

class Deque{
    Node* front;
    Node* rear;

public:
    Deque(){
        front = rear = NULL;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void pushFront(int x){
        Node* temp = new Node(x);

        if(isEmpty()){
            front = rear = temp;
            return;
        }

        temp->next = front;
        front->prev = temp;
        front = temp;
    }

    void pushRear(int x){
        Node* temp = new Node(x);

        if(isEmpty()){
            front = rear = temp;
            return;
        }

        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }

    void popFront(){
        if(isEmpty()){
            cout << "Deque is Empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if(front)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
    }

    void popRear(){
        if(isEmpty()){
            cout << "Deque is Empty\n";
            return;
        }

        Node* temp = rear;
        rear = rear->prev;

        if(rear)
            rear->next = NULL;
        else
            front = NULL;

        delete temp;
    }

    int getFront(){
        if(isEmpty()){
            cout << "Deque is Empty\n";
            return -1;
        }
        return front->data;
    }

    int getRear(){
        if(isEmpty()){
            cout << "Deque is Empty\n";
            return -1;
        }
        return rear->data;
    }

    void display(){
        if(isEmpty()){
            cout << "Deque is Empty\n";
            return;
        }

        Node* temp = front;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Deque dq;

    dq.pushFront(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushRear(30);

    dq.display();

    dq.popFront();
    dq.popRear();

    dq.display();

    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;

    //Already defined deque:
    deque<int> dq1;

    dq1.push_back(10);
    dq1.push_back(20);
    dq1.push_front(5);
    dq1.push_front(1);

    for(int x : dq1)
        cout << x << " ";

    cout << endl;

    dq1.pop_front();
    dq1.pop_back();

    for(int x : dq1)
        cout << x << " ";
    return 0;
}

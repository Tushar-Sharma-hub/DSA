//Wastage of size is not there.
#include<iostream>
using namespace std;
class Node{ //User-Defined data type.
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class Queue{ //User-defined data structure.
    public:
    Node* head;
    Node* tail;
    int s;
    Queue(){
        head=tail=NULL;
        s=0;
    }
    void push(int val){ //back act as tail.Push at tail end.
        Node* temp=new Node(val);
        if(s==0){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        s++;
    }
    void pop(){ //front act as head.Pop at head.
        if(s==0){
            cout<<"Queue is empty."<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp; //it delete the node hence there no wastage like in array implementation.
        s--;
        if(s==0) tail=NULL;
    }
    int front(){
        if(s==0){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s==0){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        return tail->val;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0) return true;
        return false;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display();
    return 0;
}
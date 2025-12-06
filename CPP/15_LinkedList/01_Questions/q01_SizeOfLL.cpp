//Find size of the linked list.
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
int sizeofLL(Node* head){
    int size=0;
    Node* temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}
int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    cout<<sizeofLL(a);
}
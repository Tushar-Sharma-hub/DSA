//Display LL using Recursion.
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
void display(Node* head){ //Pass by value the real head(a) will not change.
    if(head==NULL) return;
    cout<<head->val<<" ";
    display(head->next); //If you print after recursive call than it will print it in reverse order.
}
int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    display(a);
}
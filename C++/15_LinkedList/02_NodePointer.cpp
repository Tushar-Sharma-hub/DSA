#include<iostream>
using namespace std;
class Node{ //linked list node.
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL; //Making next default as NULL;
    }
};
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    a->next=b; //Using node pointer will help us get direct access to other node address without ussing & operator.
    b->next=c;
    c->next=d;
    display(a);
    //By using Node Pointer we can access values in easy manner.
    //Like to access c :
    cout<<endl<<"C : "<<a->next->next->val; //Without pointers we have to use brackets to avoid errors.Which can be complex for us.
}
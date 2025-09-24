//Reverse LL.
//Find size of the linked list.
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
void reverseLL(Node* head){
    if(head==NULL) return;
    reverseLL(head->next);
    cout<<head->val<<" ";
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
    cout<<endl;
    reverseLL(a);
    cout<<endl;
    display(a); //OG will not change.
}
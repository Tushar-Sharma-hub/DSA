// Limitations of Array
// Arrays are widely used, but they come with several limitations:
// Fixed Size
// Once the array size is defined, it cannot grow or shrink during runtime.
// This causes memory wastage (if array is bigger than needed) or overflow (if more data is required).
// Memory Contiguity Requirement
// Arrays need a block of contiguous memory.
// If memory is fragmented, even if total free memory is enough, array creation might fail.
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
int main(){

    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    a.next=&b;
    b.next=&c;
    c.next=&d;
    // cout<<(*(a.next)).val; //Accessing b with a.First way.
    // cout<<(a.next)->val<<endl; //Using -> .
    
    //Accessing c with a.
    // cout<<((a.next)->next)->val<<endl;

    //Accessing d with a.
    // cout<<(((a.next)->next)->next)->val;
    Node temp=a;
    while(1){
        cout<<temp.val<<endl;
        if(temp.next==NULL) break;
        temp=*(temp.next);
    }
}
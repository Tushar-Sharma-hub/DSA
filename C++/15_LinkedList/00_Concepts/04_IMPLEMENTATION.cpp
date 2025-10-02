//Implementation Of LL.
//Insertion , Deletion.
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
class LinkedList{ //User-defined data structure.
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head=tail=NULL;
        size=0;
    }
    void insertAtEnd(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertAtBegining(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertAtIdx(int idx,int val){
        if(idx<0 || idx>size){
            cout<<"Index not valid."<<endl;
            return;
        }
        if(idx==0)insertAtBegining(val);
        else if(idx==size)insertAtEnd(val);
        else{
            Node* temphead=head;
            Node* temp=new Node(val);
            for(int i=1;i<=idx-1;i++){
                temphead=temphead->next;
            }
            temp->next=temphead->next;
            temphead->next=temp;
            size++;
        }
    }
    int getAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Index not valid."<<endl;
            return -1;
        }
        if(idx==0) return head->val;
        else if(idx==size) return tail->val;
        int index=idx;
        Node* temp=head;
        while(index!=0){
            temp=temp->next;
            index--;
        }
        return temp->val;
    }

    void deleteAtHead(){
        if(size==0){
            cout<<"List is empty."<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
        size--;
        if(size==0) tail=NULL;
    }

    void deleteAtTail(){
        if(size==0){
            cout<<"List is empty."<<endl;
            return;
        }
        if(size==1){
            delete head;
            head=tail=NULL;
            size=0;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;
        size--;
    }

    void deleteAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Index not valid."<<endl;
            return;
        }
        if(idx==0){
            deleteAtHead();
        }
        else if(idx==size-1){
            deleteAtTail();
        }
        else{
            Node* temp=head;
            for(int i=1;i<idx;i++){
                temp=temp->next;
            }
            Node* toDelete=temp->next;
            temp->next=toDelete->next;
            delete toDelete;
            size--;
        }
    }
    
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtBegining(1);
    ll.display();
    ll.insertAtIdx(2,15);
    ll.display();
    cout<<"Element: "<<ll.getAtIdx(3)<<endl;
    cout<<"Size:"<<ll.size<<endl;

    ll.deleteAtHead();
    ll.display();

    ll.deleteAtTail();
    ll.display();

    ll.deleteAtIdx(1);
    ll.display();
}
//By making user-defined linked list data struct. we can insert at end in O(1) T.C bcz we are maintaining head and tail.
//In node pointer O(N) T.C is used we have to travel till end then insert at end.
//In LL to insert at idx or get element from middle we use O(N) whereas in array we use O(1).

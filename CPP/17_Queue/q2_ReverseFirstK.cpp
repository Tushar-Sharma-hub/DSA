//Reverse first K elements of a Queue.
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void display(queue<int> q){
    int n=q.size();
    cout<<"Current queue: ";
    for(int i=0;i<n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void reverseK(queue<int> & q,int k){
    int n=q.size();
    stack<int> st;
    int temp=k;
    while(temp>0){
        st.push(q.front());
        q.pop();
        temp--;
    }
    while(st.size()!=0){
        q.push(st.top());
        st.pop();
    }
    for(int i=k;i<n;i++){
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    reverseK(q,0);
    display(q);
    return 0;
}
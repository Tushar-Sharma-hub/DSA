// Reorder Queue (Interleave 1st Half with 2nd Half)
// [Do this by using one Stack only]
// Eg-1 2 3 4 5 6 then 1 4 2 5 3 6.
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> reorder(queue<int>& q){
    int n=q.size();
    int half=n/2;
    int i=1;
    stack<int> st;
    while(i<=half){
        st.push(q.front());
        q.pop();
        i++;
    }
    while(st.size()){
        q.push(st.top());
        st.pop();
    }
    while(i<=n){
        st.push(q.front());
        q.pop();
        i++;
    }
    i=1;
    while(st.size()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    while(q.size()){
        st.push(q.front());
        q.pop();
    }
    while(st.size()){
        q.push(st.top());
        st.pop();
    }
    return q;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q=reorder(q);
    while(q.size()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
#include<iostream>
#include<stack>
using namespace std;

void displayStack(stack<int>& st){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    displayStack(st);
    cout<<x<<" ";
    st.push(x);
}

void pushbottom(stack<int>& st,int val){
    stack<int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
}

void reverse(stack<int> & st){
    if(st.size()==1) return ;
    int x=st.top();
    st.pop();
    reverse(st);
    pushbottom(st,x);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    displayStack(st);
    reverse(st);
    cout<<endl;
    displayStack(st);
    return 0;
}
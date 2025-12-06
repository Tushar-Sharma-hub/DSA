#include<iostream>
#include<stack>
using namespace std;

void displayStackRev(stack<int>& st){
    if(st.size()==0) return;
    int x=st.top();
    cout<<x<<" ";
    st.pop();
    displayStackRev(st);
    st.push(x);
}

void displayStack(stack<int>& st){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    displayStack(st);
    cout<<x<<" ";
    st.push(x);
}

void pushBottom(stack<int>& st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    pushBottom(st,val);
    st.push(x);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    displayStackRev(st);
    cout<<endl;
    displayStack(st);
    pushBottom(st,-10);
    cout<<endl;
    displayStack(st);
    return 0;
}
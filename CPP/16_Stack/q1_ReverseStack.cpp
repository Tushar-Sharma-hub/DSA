//Reverse the elements in same stack.
#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> st){
    stack<int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<"Intial: ";
    print(st);
    stack<int> temp1;
    while(st.size()>0){
        temp1.push(st.top());
        st.pop();
    }
    stack<int> temp2;
    while(temp1.size()>0){
        temp2.push(temp1.top());
        temp1.pop();
    }
    while(temp2.size()>0){
        st.push(temp2.top());
        temp2.pop();
    }
    cout<<endl<<"NOW: ";
    print(st);
    return 0;
}
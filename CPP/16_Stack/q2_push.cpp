#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>& st){
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

void pushindex(stack<int>& st,int val,int idx){
    if(idx>st.size()){ 
        cout<<"INVALID INDEX!!!";
        return ;
    }
    stack<int> temp;
    while((st.size()-idx)>0){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
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
    print(st);
    pushbottom(st,5);
    cout<<endl;
    print(st);
    cout<<endl;
    pushindex(st,15,4);
    print(st);
    return 0;
}
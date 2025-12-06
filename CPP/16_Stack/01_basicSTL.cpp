#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(40);
    st.pop();
    cout<<st.top()<<endl;
    stack<int> temp;
    while(st.size()>0){
        cout<<st.top()<<" "; //Printing top to bottom.
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    while(temp.size()>0){
        cout<<temp.top()<<" "; //Printing bottom to top.
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl<<st.top();
    return 0;
}
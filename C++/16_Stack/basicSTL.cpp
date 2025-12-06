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
    cout<<st.top();
    return 0;
}
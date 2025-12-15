//Evaluate infix to prefix expression.
#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;
}

int solve(char ch,int val1,int val2){
    if(ch=='*') return val1*val2;
    if(ch=='/') return val1/val2;
    if(ch=='-') return val1-val2;
    return val1+val2;
}

int prefixEvaluation(string str){
    stack<int> st;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9') st.push(str[i]-'0');
        else{
            char ch=str[i];
            int val1=st.top();st.pop();//here val1 will be at top bcz we moving from back.
            int val2=st.top();st.pop();
            int ans=solve(ch,val1,val2);
            st.push(ans);
        } 
    }
    return st.top();
}

string prefixToPostfix(string str){
    stack<string> st;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            st.push(to_string(str[i]-'0'));
        }
        else{
            char ch=str[i];
            string val1=st.top(); st.pop();
            string val2=st.top(); st.pop();
            string ans = val1 + val2 + ch;
            st.push(ans);
        }
    }
    return st.top();
}

string prefixToInfix(string str){
    stack<string> st;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            st.push(to_string(str[i]-'0'));
        }
        else{
            char ch=str[i];
            string val1=st.top(); st.pop();
            string val2=st.top(); st.pop();
            string ans = "(" + val1 + ch + val2 + ")";
            st.push(ans);
        }
    }
    return st.top();
}


int main(){
    string str="(2+6)*(4/2-3)";
    string ans;
    stack<string> val;
    stack<char> op;

    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            val.push(to_string(str[i]-'0'));
        }
        else if(str[i]=='('){
            op.push(str[i]);
        }
        else if(str[i]==')'){
            while(op.top()!='('){
                char ch=op.top(); op.pop();
                string val2=val.top(); val.pop();
                string val1=val.top(); val.pop();
                ans=ch+val1+val2;
                val.push(ans);
            }
            op.pop();
        }
        else{
            if(op.size()==0 || op.top()=='(' || priority(op.top())<priority(str[i])){
                op.push(str[i]);
            }
            else{
                while(op.size()!=0 && op.top()!='(' && priority(op.top())>=priority(str[i])){
                    char ch=op.top(); op.pop();
                    string val2=val.top(); val.pop();
                    string val1=val.top(); val.pop();
                    ans=ch+val1+val2;
                    val.push(ans);
                }
                op.push(str[i]);
            }
        }
    }

    while(!op.empty()){
        char ch=op.top(); op.pop();
        string val2=val.top(); val.pop();
        string val1=val.top(); val.pop();
        ans=ch+val1+val2;
        val.push(ans);
    }

    cout<<"Infix to Prefix:"<<val.top()<<endl;
    cout<<"Prefix evaluation: "<<prefixEvaluation(val.top())<<endl;
    string prefix = val.top();

    cout<<"Prefix to Postfix: "<<prefixToPostfix(prefix)<<endl;
    cout<<"Prefix to Infix: "<<prefixToInfix(prefix)<<endl;
}
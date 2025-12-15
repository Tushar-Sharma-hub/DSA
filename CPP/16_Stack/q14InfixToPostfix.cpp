//Evaluate infix to postfix expression. 
//Evaluate postfix expression.
//Postfix to infix and prefix. 
#include<iostream>
#include<stack>
using namespace std;

int solve(char ch,int val1,int val2){
    if(ch=='*') return val1*val2;
    if(ch=='/') return val1/val2;
    if(ch=='-') return val1-val2;
    return val1+val2;
}

int priority(char ch){
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;
}

int postfixEvaluation(string str){
    stack<int> st;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0' && str[i]<='9'){ st.push(str[i]-48);}
        else{
            char ch=str[i];
            int val2=st.top();st.pop();
            int val1=st.top();st.pop();
            int ans=solve(ch,val1,val2);
            st.push(ans);
        }
    }
    return st.top();
}

string postfixToInfix(string str){
    string ans;
    stack<string> st;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0' && str[i]<='9'){ st.push(to_string(str[i]-'0'));}
        else{
            char ch=str[i];
            string val2=st.top();st.pop();
            string val1=st.top();st.pop();
            ans = "(" + val1 + ch + val2 + ")";
            st.push(ans);
        }
    }
    return ans;
}

string postfixToPrefix(string str){
    string ans;
    stack<string> st;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0' && str[i]<='9'){ st.push(to_string(str[i]-'0'));}
        else{
            char ch=str[i];
            string val2=st.top();st.pop();
            string val1=st.top();st.pop();
            ans=ch+val1+val2;
            st.push(ans);
        }
    }
    return ans;
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
                ans=val1+val2+ch;
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
                    ans=val1+val2+ch;
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
        ans=val1+val2+ch;
        val.push(ans);
    }

    cout<<"Infix to Postfix: "<<val.top()<<endl;
    cout<<"Postfix Evaluation: "<<postfixEvaluation(ans)<<endl;

    cout<<endl<<"Postfix to Infix: ";
    string infix=postfixToInfix(ans);
    for(int i=0;i<infix.size();i++){
        cout<<infix[i];
    }
    cout<<endl<<"Postfix to Prefix: ";
    string prefix=postfixToPrefix(ans);
    for(int i=0;i<prefix.size();i++){
        cout<<prefix[i];
    }
}
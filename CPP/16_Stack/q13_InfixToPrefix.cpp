//Evaluate infix to prefix expression.
#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;
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

    cout<<val.top();
}
//Evaluate infix expression when given in string.
#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch=='*' || ch=='/') return 2;
    return 1;
}

int solve(char ch,int val1,int val2){
    if(ch=='*') return val1*val2;
    if(ch=='/') return val1/val2;
    if(ch=='-') return val1-val2;
    return val1+val2;
}

int main(){
    string str="2+6*4/8-3";
    stack<int> val;
    stack<int> op;
    for(int i=0;i<str.length();i++){
        if(str[i]>=48 && str[i]<=57){ //digit
            val.push(str[i]-48);
        }
        else{ //operation
            if(op.size()==0 || priority(op.top())<priority(str[i])) op.push(str[i]);
            else{
                while(op.size()>0 && priority(op.top())>=priority(str[i])){
                    char ch=op.top();
                    op.pop();
                    int val2=val.top();
                    val.pop();
                    int val1=val.top();
                    val.pop();
                    int ans=solve(ch,val1,val2);
                    val.push(ans);
                }
                op.push(str[i]);
            }
        }
    }
    while(op.size()>0){
        char ch=op.top();
        op.pop();
        int val2=val.top();
        val.pop();
        int val1=val.top();
        val.pop();
        int ans=solve(ch,val1,val2);
        val.push(ans);
    }
    cout<<val.top();
}
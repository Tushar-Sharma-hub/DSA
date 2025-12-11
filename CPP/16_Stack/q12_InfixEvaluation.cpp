//Evaluate infix expression when given in string.
#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0; // for '('
}

int solve(char ch,int val1,int val2){
    if(ch=='*') return val1*val2;
    if(ch=='/') return val1/val2;
    if(ch=='-') return val1-val2;
    return val1+val2;
}

int main(){
    string str="(2+6)*(4/2)-3";
    stack<int> val;
    stack<char> op;

    for(int i=0;i<str.length();i++){
        
        // Digit
        if(str[i] >= '0' && str[i] <= '9'){
            val.push(str[i]-'0');
        }

        // Opening bracket
        else if(str[i] == '('){
            op.push('(');
        }

        // Closing bracket
        else if(str[i] == ')'){
            while(op.top() != '('){
                char ch = op.top(); op.pop();
                int val2 = val.top(); val.pop();
                int val1 = val.top(); val.pop();
                val.push( solve(ch,val1,val2) );
            }
            op.pop(); // remove '('
        }

        // Operator + - * /
        else {
            while(!op.empty() && op.top()!='(' && priority(op.top()) >= priority(str[i])){
                char ch = op.top(); op.pop();
                int val2 = val.top(); val.pop();
                int val1 = val.top(); val.pop();
                val.push( solve(ch,val1,val2) );
            }
            op.push(str[i]);
        }
    }

    // Solve remaining operators
    while(!op.empty()){
        char ch = op.top(); op.pop();
        int val2 = val.top(); val.pop();
        int val1 = val.top(); val.pop();
        val.push( solve(ch,val1,val2) );
    }

    cout << val.top();
}

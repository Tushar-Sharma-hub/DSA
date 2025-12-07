//Valid Brackets '()'.
#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    if(s.size()%2!=0) return false;
    stack<char> temp;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') temp.push(s[i]);
        else{
            if(temp.size()==0) return false;
            temp.pop();
        }
    }
    if(temp.size()==0) return true;
    return false;
}

int main(){
    string s=")";
    if(isValid(s)) cout<<"True lil bro.";
    else cout<<"False lil bro.";
    return 0;
}
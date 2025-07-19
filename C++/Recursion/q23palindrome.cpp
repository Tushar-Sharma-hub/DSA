//Check palindrome using recursive call.
#include<iostream>
using namespace std;

bool ispalindrome(string s,int i,int j){
    if(i>=j) return true;
    if(s[i]!=s[j]) return false;
    else return ispalindrome(s,++i,--j);
}

int main(){
    string s="racecar";
    cout<<ispalindrome(s,0,s.size()-1);
    return 0;
}
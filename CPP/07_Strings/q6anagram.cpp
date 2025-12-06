//Ques : Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Input: s = physicswallah, t = wallahphysics
// Output: YES -LC242

#include<iostream>
using namespace std;

int main(){
    string s;
    string t;
    cout<<"s= ";
    getline(cin,s);
    cout<<"t= ";
    getline(cin,t);
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t) cout<<1;
    else cout<<0;
    return 0;
}
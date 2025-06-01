//Given a string consisting of lowercase English alphabets. Print the character that is occurring most number of times.
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<int> v(26,0);
    string s;
    cout<<"String: ";
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        char c=s[i];
        int ascii=(int)c;
        v[ascii-97]++;
    }
    int mx=0;
    for(int i=0;i<26;i++){
        if(v[i]>mx) mx=v[i];
    }
    for(int i=0;i<26;i++){
        if(v[i]==mx){
            int ascii=i+97;
            char ch=(char)ascii;
            cout<<ch<<" "<<mx<<" times.";
        }
    }
    return 0;
}
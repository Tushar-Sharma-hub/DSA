//Given n strings consisting of digits from 0 to 9. Return the index of string which has maximum value. (Take 0 based indexing)
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s1="0123";
    string s2="234";
    string s3="0789";
    string s4="9123";
    string s5="2634";
    string s6="7789";
    vector<string> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);
    v.push_back(s5);
    v.push_back(s6);
    int max=0;
    for(int i=0;i<v.size();i++){
        int x=stoi(v[i]);
        if(x>max) max=x;
    }
    for(int i=0;i<v.size();i++){
        if(stoi(v[i])==max) cout<<max<<" "<<i;
    }
    return 0;
}
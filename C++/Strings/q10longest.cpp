//Input n strings and write a program to find the longest common prefix string of all the strings.--LC14
#include<iostream>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n=strs.size();
    sort(strs.begin(),strs.end());
    string first=strs[0];
    string last=strs[n-1];
    string s="";
    for(int i=0;i<min(first.size(),last.size());i++){
        if(first[i]==last[i]) s+=first[i];
        else return s;
    }
    return s;
}
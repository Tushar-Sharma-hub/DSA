#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> freq(26,0);
    int count=0;
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']+=1;
    }
    for(int i=0;i<freq.size();i++){
        if(freq[i]>0) count++;
    }
    if(count%2==0) cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
    return 0;
}
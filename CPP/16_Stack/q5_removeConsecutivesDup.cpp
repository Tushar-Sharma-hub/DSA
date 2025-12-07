//Remove consecutives duplicates.
#include<iostream>
#include<stack>
using namespace std;

string removeCons(string s){
    stack<char> temp;
    temp.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(s[i]==temp.top()) continue;
        else temp.push(s[i]);
    }
    string ans;
    while(temp.size()!=0){
        ans.push_back(temp.top());
        temp.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s="aaaabcccdaabffg";
    s=removeCons(s);
    int i=0;
    while(i<s.size()){
        cout<<s[i];
        i++;
    }
    return 0;
}
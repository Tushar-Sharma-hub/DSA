// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// LC-22
#include<iostream>
using namespace std;

void generateparenthesis(vector<string>& ans,string s,int ob,int cb,int n){ //ob-opening bracket cb-closing bracket.
    if(cb==n){
        ans.push_back(s);
        return;
    }
    if(ob<n) generateparenthesis(ans,s+'(',ob+1,cb,n);
    if(cb<ob) generateparenthesis(ans,s+')',ob,cb+1,n);
}

int main(){
    int n=3;
    vector<string> ans;
    generateparenthesis(ans,"",0,0,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
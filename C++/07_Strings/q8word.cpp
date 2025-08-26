//Given a sentence 'str', return the word that is occurring most number of times in that sentence.
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s;
    cout<<"String: ";
    getline(cin,s);
    stringstream ss(s);
    string temp;
    vector<string> v;
    while(ss>>temp){
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int count=1,maxc=1;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) count++;
        else count=1;
        maxc=max(maxc,count);
    }
    count=1;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) count++;
        else count=1;
        if(count==maxc) cout<<v[i]<<" "<<maxc<<endl;
    }
    return 0;
}
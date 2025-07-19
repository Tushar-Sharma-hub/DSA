//Generate all binary strings of length n without consecutive 1's.

#include<iostream>
using namespace std;

void generatebinary(string s,int n){
    if(s.length()==n) {
        cout<<s<<endl;
        return;
    }
    generatebinary(s+'0',n);
    if(s[s.size()-1]!=1) generatebinary(s+'1',n);
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    generatebinary("",n);
    return 0;
}
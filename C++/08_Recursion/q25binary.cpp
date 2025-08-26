//Generate all binary strings of length n without consecutive 1's.

#include<iostream>
using namespace std;

void generatebinary(string s,int n){
    if(s.length()==n) {
        cout<<s<<endl;
        return;
    }
    generatebinary(s+'0',n);
    if(s=="" || s[s.length()-1]=='0') generatebinary(s+'1',n);
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    generatebinary("",n);
    return 0;
}

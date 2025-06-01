//Sorting is based on ascii values.
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    sort(s.begin(),s.end());
    cout<<s;
    return 0;
}
//Strings are character arrays.
#include<iostream>
#include<string>
using namespace std;
int main(){
    // string str="Tushar Sharma";
    // cout<<str;
    string s;
    // cin>>s; //only if given string have no spaces.
    getline(cin,s); //withspaces.
    cout<<s;

}
//String built-in fxn.
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="Tushar";
    // cout<<s.size(); //size and length both are same.
    // cout<<endl<<s.length();
    cout<<s<<endl;
    s.push_back('e'); //only push a char.
    cout<<s<<endl;
    s.pop_back(); //pop last element
    cout<<s<<endl;

    string t="sharma";
    cout<<s+t<<endl; //plus sign is used to append.
    cout<<s+"abcd"<<endl;

    reverse(s.begin(),s.end()); //reverse
    cout<<s<<endl;
}
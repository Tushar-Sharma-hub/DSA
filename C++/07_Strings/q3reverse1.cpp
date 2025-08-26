//Input a string of even length and reverse the first half of the string.
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"Enter the string(of even length):";
    getline(cin,s);
    if(s.length()%2!=0){
        cout<<"Please enter a string even!!!";
        return 0;
    }
    int i=0;
    int half=(s.size())/2;
    reverse(s.begin(),s.begin()+half);
    cout<<s;
    return 0;
}
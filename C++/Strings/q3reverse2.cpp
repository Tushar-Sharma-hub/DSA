//Input a string of length greater than 5 and reverse the substring from position 2 to 5 using inbuilt functions.
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    if(s.size()<=5){
        cout<<"String length hould be greater than 5.";
        return 0;
    }
    reverse(s.begin()+1,s.begin()+5);
    cout<<s;
}
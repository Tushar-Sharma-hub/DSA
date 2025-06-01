//Input a string of length n and count all the vowels in the given string.
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"Enter the string:";
    getline(cin,s);
    int i=0,count=0;
    while(s[i] != '\0'){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            count++;
        }
        i++;
    }
    cout<<"Total lower case vowels are: "<<count;
}
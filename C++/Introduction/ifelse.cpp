#include<iostream>
using namespace std;
int main(){
    char character;
    cout<<"Enter a character:";
    cin>>character;
    if(character>='a' && character<='z'){
        cout<<"The charcter entered is lower cased.";
    }
    else if(character>='A' && character<='Z'){
        cout<<"The charcter entered is Upper cased.";
    }
    else{
        cout<<"Enter valid character";
    }
    return 0;
}
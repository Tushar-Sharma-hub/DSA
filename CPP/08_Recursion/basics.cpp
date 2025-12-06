//Print goodmorning 'n' no. of times,where n is user input.Using recursion.
#include<iostream>
using namespace std;

void goodmorning(int n){
    if(n==0) return;
    cout<<"Good morning."<<endl;
    goodmorning(n-1);
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    goodmorning(n);
    return 0;
}
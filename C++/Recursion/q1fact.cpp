//Make a function which calculates the factorial of n using recursion.
#include<iostream>
using namespace std;

int fact(int n){
    if(n==1 || n==0) return 1; //fact(1) is 1.
    return n*fact(n-1);
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int ans=fact(n);
    cout<<"Factorial: ";
    cout<<ans;
    return 0;
}
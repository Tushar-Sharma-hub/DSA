//print sum from 1 to n.(parameterised)
#include<iostream>
using namespace std;

void sum(int i,int n){
    if(n==0) {
        cout<<i;
        return;
    }
    sum(i+n,n-1);
}

int sum2(int n){
    if(n==0) return 0;
    return n+sum2(n-1);
}

int main(){
    sum(0,3);
    cout<<endl<<sum2(6);
    return 0;
}
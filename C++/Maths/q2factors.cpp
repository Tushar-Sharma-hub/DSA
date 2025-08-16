//Factors of n in time complexity root(n)
#include<iostream>
using namespace std;

void printfactors(int n){
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0) cout<<i<<" ";
    }
    for(int i=sqrt(n);i>=1;i--){
        if(n%i==0) cout<<n/i<<" ";
    }
}

int main(){
    printfactors(28);
    return 0;
}
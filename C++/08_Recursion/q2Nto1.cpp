//Print n to 1.Using recursion
#include<iostream>
using namespace std;

void nto1(int n){
    if(n==0) return;
    cout<<n<<endl;
    nto1(n-1);
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    nto1(n);
    return 0;
}
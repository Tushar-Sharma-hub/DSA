#include<iostream>
using namespace std;

int dectobin(int dec){
    int ans=0,pow=1;
    while(dec>0){
        int rem=dec%2;
        dec/=2;
        ans+=(rem*pow);
        pow*=10;
    }
    return ans;
}

int bintodec(int bin){
    int ans=0,pow=1;
    while(bin>0){
        int rem=bin%10;
        ans+=rem*pow;
        bin/=10;
        pow*=2;
    }
    return ans;
}

int main(){
    int n,n1,binary=0;
    cout<<"Enter Decimal number:";
    cin>>n;
    cout<<"Binary number:"<<dectobin(n)<<endl;

    cout<<"Enter Binary number:";
    cin>>n1;
    cout<<"Decimal number:"<<bintodec(n1);
    return 0;
}
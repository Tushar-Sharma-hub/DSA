//Tower of hanoi.
#include<iostream>
using namespace std;

void hanoi(int n,char s,char h,char d){ //source helper and destination.
    if(n==0) return;
    hanoi(n-1,s,d,h);
    cout<<s<<"->"<<d<<endl;
    hanoi(n-1,h,s,d);
}

int main(){
    int n;
    cout<<"Enter number of plates:";
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}
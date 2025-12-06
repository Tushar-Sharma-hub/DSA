#include<iostream>
using namespace std;
int main(){
    int x=4;
    int* p=&x;//p is the pointer which stores the address of x.
    cout<<&x<<endl;//& is address operator .
    cout<<p<<endl; 
    cout<<*p;//* is the value opperator.
    return 0;
}
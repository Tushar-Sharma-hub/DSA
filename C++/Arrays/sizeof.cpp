#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,343,4,3,24,4,34,24,343,34,3,4,42};
    int size=sizeof(arr)/sizeof(arr[0]); //size of array divide by size of one element in the array.
    cout<<size;
    return 0;
}
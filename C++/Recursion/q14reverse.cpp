//Print all the elements of an array in reverse order.Using recursion.
#include<iostream>
#include<vector>
using namespace std;

void reverse(int arr[],int size){
    if(size==0) return;
    cout<<arr[size-1]<<endl;
    reverse(arr,size-1);
}

int main(){
    int arr[9]={1,2,3,4,6,5,7,5,4};
    reverse(arr,9);
    return 0;
}
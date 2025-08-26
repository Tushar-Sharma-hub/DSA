// Given an array of integers, print a sum triangle using recursion from it such that the first level has
// all array elements. After that, at each level the number of elements is one less than the previous
// level and elements at the level will be the sum of consecutive two elements in the previous level.
// So, if sample input is [5, 4, 3, 2, 1], sample output will be:
// [5, 4, 3, 2, 1]
// [9, 7, 5, 3]
// [16, 12, 8]
// [28, 20]
// [48]
#include<iostream>
using namespace std;

void sum(int arr[],int size,int i){
    if(size==1) {
        cout<<arr[0];
        return;
    }
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    cout<<endl;
    while(i<size-1){
        arr[i]+=arr[i+1];
        i++;
    }
    sum(arr,size-1,0);
}

int main(){
    int tri[4]={4,3,2,1};
    sum(tri,4,0);
    return 0;
}
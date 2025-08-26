//Given a sorted array of n elements and a target 'x'. Find the first occurrence of 'x' in the array. If 'x' does not exist return -1.
//LC-34
#include<iostream>
using namespace std;

int main(){
    int arr[12]={1,2,3,3,3,13,13,14,15,17,19,20};
    int n=12;
    int x;
    cout<<"Enter target:";
    cin>>x;
    int low=0,high=n-1;
    int result=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            result=mid;
            high=mid-1; //going to the left as possible to find the first occurence .For last we can use low=mid+1.
        }
        else if(arr[mid]<x) low=mid+1;
        else high=mid-1;
    }
    if(result != -1)
        cout << "First occurrence at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
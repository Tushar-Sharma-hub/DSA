//Given a sorted integer array and an integer 'x', find the lower bound of x.
#include<iostream>
using namespace std;

int main(){
    int arr[9]={1,2,3,13,14,15,17,19,20};
    int n=9;
    int x=16; //lower bound is 15 for given array.
    int low=0,high=n-1;
    bool flag=false;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            flag=true;
            cout<<arr[mid-1];
            break;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else high=mid-1;
    }
    if(flag==false) cout<<arr[high]; 
    return 0;
}
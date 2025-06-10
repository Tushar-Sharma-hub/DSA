//Search in a Sorted Infinite Array.
#include<iostream>
using namespace std;

int searchInfiniteSortedArray(int arr[], int target){
    int low=0,high=1;
    while(arr[high]<target){ //Find bounds
        low=high;
        high=high*2; //O(logn)
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) low=mid+1;
        else high=mid-1; 
    }
    return -1;//not found.
}
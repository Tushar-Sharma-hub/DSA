// Cyclic Sort is used for arrays containing numbers in a fixed range, usually 1 to n or 0 to n−1.
// It works by placing each element directly at its correct index (value - 1 or value).
// If an element is not at its correct position, swap it with the element at its correct index.
// Continue until every element is in its correct position; each element is moved at most once to its final place.
// Time Complexity: O(n), Space Complexity: O(1).
#include<iostream>
using namespace std;

int main(){
    int arr[]={4,1,6,2,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //cycle sort
    int i=0;
    while(i<n){
        int correctidx=arr[i]-1;
        if(i==correctidx) i++;
        else{
            swap(arr[i],arr[correctidx]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
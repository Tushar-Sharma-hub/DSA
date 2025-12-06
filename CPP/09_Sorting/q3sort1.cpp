// Given an array with N distinct elements, convert the given array to a form where all elements are in the range from 0 to N-1. 
// The order of elements is the same, i.e., O is placed in the place of the smallest element, 1 is placed for the second smallest element,
//  ... N-1 is placed for the largest element.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int> nums(n);
    vector<int> isVisited(n,0);
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int x=0;
    for(int i=0;i<n;i++){
        int min=INT_MAX;
        int mindx=-1;
        for(int j=0;j<n;j++){
            if(isVisited[j]==1) {continue;}
            else if(min>nums[j]){
                min=nums[j];
                mindx=j;
            }
        }
        nums[mindx]=x;
        isVisited[mindx]=1;
        x++;
    }
    return 0;
}
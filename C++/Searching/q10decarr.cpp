//search a number in array which is decresing.
#include<iostream>
using namespace std;

int main(){
    int arr[6]={6,5,4,3,2,1};
    int n=6;
    int x;
    cout<<"Enter element to search:";
    cin>>x;
    int low=0,high=n-1,idx=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){ 
            idx=mid;
            break;
        }
        else if(arr[mid]>x) low=mid+1;
        else high=mid-1;
    }
    if(idx==-1) cout<<"Not found!!!";
    else cout<<"Found at index :"<<idx;
    return 0;
}
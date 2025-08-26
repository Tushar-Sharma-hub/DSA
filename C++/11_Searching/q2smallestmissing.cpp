//Given a sorted array of non-negative distinct integers, find the smallest missing non-negative element in it.
#include<iostream>
using namespace std;

int main(){
    int arr[6]={0,1,3,4,6,7};
    int n=6;

    //Linear approach with O(n)
    // for(int i=0;i<n;i++){
    //     if(arr[i]!=i) cout<<"Smallest missing element is: "<<i;
    // }

    int low=0,high=n-1,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==mid) low=mid+1;//If arr[mid]==mid then previous elements should be also equal as they are non-negative distinct integers.
        else{
            ans=mid;//if arr[mid]!=mid then ans can be mid but we to check all previous for smallest so move high.
            high=mid-1;
        }
    }
    cout<<"Smallest missing element is: "<<ans;
    return 0;
}
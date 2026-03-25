//Convert given array into heap.
#include<iostream>
using namespace std;

void heapify(int i,int arr[],int n){
    while(true){
        int l=2*i,r=2*i+1;
        if(l>=n) break;
        if(r>=n){
            if(arr[i]>arr[l]){
                swap(arr[i],arr[l]);
                i=l;
            }
            break;
        }
        if(arr[l]<arr[r]){
            if(arr[i]>arr[l]){
                swap(arr[i],arr[l]);
                i=l;
            }
            else break;
        }
        else{
            if(arr[i]>arr[r]){
                swap(arr[i],arr[r]);
                i=r;
            }
            else break;
        }
    }
}

int main(){
    int arr[]={-1,10,2,14,11,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=n/2;i>=1;i--){
        heapify(i,arr,n);
    }
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
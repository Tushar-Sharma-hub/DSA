// Write a Program to find Kth smallest element in an array using QuickSort.
// Quick Select.
#include<iostream>
using namespace std;

int partition(int arr[],int si,int ei){
    int pivot=arr[(si+ei)/2],count=0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(arr[i]<=pivot) count++;
    }
    int pivotidx=count+si;
    swap(arr[(si+ei)/2],arr[pivotidx]);
    int i=si,j=ei;
    while(i<j){
        if(pivot>=arr[i]) i++;
        if(pivot<arr[j]) j--;
        else if(pivot<arr[i] && pivot>=arr[j]){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;
}

int kthsmallest(int arr[],int stridx,int endidx,int k){
    int pivotidx=partition(arr,stridx,endidx);
    if(pivotidx+1==k) return arr[pivotidx];
    else if(pivotidx+1<k) return kthsmallest(arr,pivotidx+1,endidx,k);
    else return kthsmallest(arr,stridx,pivotidx-1,k);
}

int main(){
    int arr[]={5,1,8,2,7,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k=4;
    cout<<kthsmallest(arr,0,n-1,k);
    
}
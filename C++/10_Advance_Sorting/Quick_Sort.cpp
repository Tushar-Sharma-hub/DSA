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

void quicksort(int arr[],int stridx,int endidx){
    if(stridx>=endidx) return;
    int pivotidx=partition(arr,stridx,endidx);
    quicksort(arr,stridx,pivotidx-1);
    quicksort(arr,pivotidx+1,endidx);
}

int main(){
    int arr[]={5,1,8,2,7,6,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
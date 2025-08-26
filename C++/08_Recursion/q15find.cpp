//Print index of a given element in an array. If not present, print -1.
#include<iostream>
using namespace std;

int find(int arr[],int a,int n,int ele){
    if(a==n) return -1;
    if(arr[a]==ele) return a;
    return find(arr,a+1,9,5);
}

int main(){
    int arr[9]={1,2,3,4,5,6,7,8,9};
    int idx=find(arr,0,9,5);
    cout<<idx;
    return 0;
}
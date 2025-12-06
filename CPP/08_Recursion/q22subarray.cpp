#include<iostream>
using namespace std;

void subarray(vector<int> v,int arr[],int idx,int size){
    if(idx==size){
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        return;
    }
    subarray(v,arr,idx+1,size);
    if(v.size()==0 || v[v.size()-1]==arr[idx-1]){
        v.push_back(arr[idx]);
        subarray(v,arr,idx+1,size);
    }
}

int main(){
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> ans;
    // brute force. 
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         for(int k=i;k<=j;k++){
    //             cout<<arr[k];
    //         }
    //         cout<<endl;
    //     }
    // }
    subarray(ans,arr,0,n);

    return 0;
}
// Print all increasing sequences of length k from first n natural numbers.

#include<iostream>
using namespace std;

void printSubset(int arr[], int n, int idx, vector<int> ans, int k) {
    if(idx==n){
        if(ans.size()==k){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(ans.size()+(n-idx)<k) return; //Time complexity better.
    printSubset(arr,n,idx+1,ans,k);
    ans.push_back(arr[idx]);
    printSubset(arr,n,idx+1,ans,k);
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    int k;
    cout<<"Enter k:";
    cin>>k;
    printSubset(arr,n,0,v,k);
    return 0;
}
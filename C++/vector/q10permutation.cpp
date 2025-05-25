//Find the next permutation of array.(if not possible then print the sorted array in asc.)-31
#include<iostream>
#include<vector>
using namespace std;

void nextPermutation(vector<int>& v){
    int n=v.size();
    int pivotidx=-1;
    //1.Find the pivot index.
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            pivotidx=i;
            break;
        }
    }
    if(pivotidx==-1){
        reverse(v.begin(),v.end());
        return;
    }
    //2.Sorting/Reverse after pivot.
    reverse(v.begin()+pivotidx+1,v.end());
    //3.Find just greater element than idx and Swap pivotidx and greater element.
    int j=-1;
    for(int i=pivotidx+1;i<n;i++){
        if(v[i]>v[pivotidx]){
            j=i;
            break;
        }
    }
    swap(v[pivotidx],v[j]);
}

int main(){
    vector<int> v;
    int n;
    cout<<"Enter the number to find its next permutation:";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    nextPermutation(v);
    cout<<"Next permuation is:";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
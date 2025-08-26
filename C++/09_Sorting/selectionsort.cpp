//It is a unstable sort algo.
//Working- Find the smallest element index swap it with first element then second ,continue till sorted. 
#include<iostream>
#include<vector>
using namespace std;

void selectionsort(vector<int> & v){
    int n=v.size();
    for(int i=0;i<n;i++){
        int smallestidx=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[i]) smallestidx=j;
        }
        swap(v[i],v[smallestidx]);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    selectionsort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
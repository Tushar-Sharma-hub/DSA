//Time Complexity-O(n.logn)
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& a,vector<int>& b,vector<int>& c){ //To merge two sorted array
    int n1=a.size(),n2=b.size();
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            c[k]=a[i];
            k++;
            i++;
        }
        else{
            c[k]=b[j];
            k++;
            j++;
        }
    }
    //for remaining elements.
    if(i==n1){
        while(j<n2){
            c[k]=b[j];
            k++;
            j++;
        }
    }
    if(j==n2){
        while(i<n1){
            c[k]=a[i];
            k++;
            i++;
        }
    } 
}

void mergesort(vector<int> & v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2,n2=n-n/2;
    vector<int> a(n1),b(n2);
    //copy paste
    for(int i=0;i<n1;i++) a[i]=v[i];
    for(int i=0;i<n2;i++) b[i]=v[i+n1];
    //Recursion
    mergesort(a);
    mergesort(b);
    //merge
    merge(a,b,v);
}

int main(){
    int arr[]={5,1,3,0,4,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);//To copy any array in a vector we have to do this.
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergesort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
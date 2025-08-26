//Reverse an array without any extra array
//Logic-We we take i at starting j at end then swap it until i<=j.
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cout<<"Enter "<<i+1<<" element:";
        cin>>x;
        v.push_back(x);
    }
    int i=0,j=n-1;
    while(i<j){
        int temp=v[i]; //swap
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
    cout<<"After reverse:";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
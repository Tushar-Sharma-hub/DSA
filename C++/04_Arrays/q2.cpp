//Calculate the sum of all the elements in the given array.
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" element:";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<"The sum of the elements is:"<<sum;
    return 0;
}
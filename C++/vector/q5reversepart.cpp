//Reverse part of a array.
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size :";
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cout<<"Enter "<<i+1<<" element:";
        cin>>x;
        v.push_back(x);
    }
    int i,j;
    cout<<"Enter part(index) of the array you want to reverse(i,j):";
    cin>>i>>j;
    if (i < 0 || j >= n || i > j) {
        cout << "Invalid indices!" << endl;
        return 1;
    }
    while(i<j){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
    cout<<"After reversing the part form "<<i<<" to "<<j<<" :";
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
}
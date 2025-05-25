#include<iostream>
using namespace std;
int main(){
    int n;
    vector<int> v;
    cout<<"Enter n:";
    cin>>n;
    for(int i=0;i<n;i++){ //Input(we can use size() operator as intially it will be 0)
        int x;
        cout<<"Enter "<<i+1<<" element:";
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
//find the last occurence of x in the array.
#include<iostream>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);
    v.push_back(6);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.push_back(7);
    v.push_back(1);
    int x;
    cout<<"Enter element to check the last occurence of that element:";
    cin>>x;
    int index=0;

    // Simple way more time complexity
    // for(int i=0;i<v.size();i++){
    //     if(v[i]==x) index=i;
    // }
    // cout<<"The last occurence of "<<x<<" is at "<<index<<" index.";

    //Check from backward less time complexity.
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
            index=i;
            cout<<"The last occurence of "<<x<<" is at "<<index<<" index.";
            break;
        }
    }
}
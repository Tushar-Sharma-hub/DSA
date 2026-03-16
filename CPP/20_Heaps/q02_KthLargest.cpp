// Find the kth largest element in a given array.
#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,-1,-2,3,4,-3,-5,5,7};
    int k=3;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int ele:arr){
        q.push(ele);
        if(q.size()>k) q.pop();
    }
    cout<<q.top();
    return 0;
}
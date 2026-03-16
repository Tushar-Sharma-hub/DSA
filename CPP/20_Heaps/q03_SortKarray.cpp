// Sort a 'k' sorted array (sort a nearly sorted array).
// k is the maximum distance an element is from its correct position in the sorted order.
#include<iostream>
using namespace std;

int main(){
    int arr[]={10, 9, 8, 7, 4, 70, 60, 50};
    int k=4;
    priority_queue<int,vector<int>,greater<int>> q;
    int idx=0;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        q.push(arr[i]);
        if(q.size()>k){
            arr[idx++]=q.top();
            q.pop();
        }
    }
    while(q.size()){ arr[idx++]=q.top(); q.pop();}
    for(int ele: arr){
        cout<<ele<<" ";
    }
    return 0;
}
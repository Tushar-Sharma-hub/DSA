// Find the kth smallest element in a given array.


//It can be done by other ways also like sort then return arr[k-1] but t.c is O(nlogn), we can do it with nlogk using heaps.
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int arr[] = {7,10,4,3,20,15};
    int k = 3;
    //Bekar approach:(using min heap)
    // priority_queue<int,vector<int>,greater<int>> q;
    // for(int ele:arr){
    //     q.push(ele);
    // }
    // while(k!=1 && q.size()!=0){
    //     q.pop();
    //     k--;
    // }
    // cout<<q.top()<<" ";
    // It is bad because we are pushing all the elements in the heap and then popping k-1 elements. Time complexity is O(nlogn) + O(klogn) = O(nlogn)
    // S.C: O(n) for the heap.


    //Better approach:(Using maxHead)
    priority_queue<int> q;
    for(int ele:arr){
        q.push(ele);
        if(q.size()>k){
            q.pop();
        }
    }
    cout<<q.top()<<" ";
    //This is better because we are maintaining a heap of size k, so the time complexity is O(nlogk) which is better than O(nlogn) when k is small compared to n.
    //A.C: O(k) for the heap.(auxiliary space complexity is extra space used.)
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;

int main(){
    //Priority Queue: A priority queue is a data structure that allows us to efficiently retrieve the maximum (or minimum) element. 
    //In C++, the default implementation of a priority queue is a max-heap, which means that the largest element is always at the top.
    priority_queue<int> pq; //max head by deufalt.
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(35);
    cout<<pq.top()<<" "; //max element at top.
    pq.pop();
    cout<<pq.top()<<" ";
    priority_queue<int,vector<int>,greater<int>> pq; //min heap by default.
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(35);
    cout<<pq.top()<<" "; //min element at top.
    pq.pop();
    cout<<pq.top()<<" ";
//     Problem Identification
// 1) kth smallest, kth largest. Top k frequent elements, Closest k
// 2) At any point of time, minimum / maximum elements are required
// 3) Sorting (sometimes, not always)
    return 0;
}
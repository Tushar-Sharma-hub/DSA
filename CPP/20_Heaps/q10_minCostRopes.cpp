// Minimum Cost of ropes
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. 
// The cost to connect two ropes is the sum of their lengths. 
class Solution {
  public:
    int minCost(vector<int>& arr) {
        int cost=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int ele:arr){
            pq.push(ele);
        }
        while(pq.size()){
            if(pq.size()==1) return cost;
            int m1=pq.top();pq.pop();
            int m2=pq.top();pq.pop();
            cost+=(m1+m2);
            pq.push(m1+m2);
        }
        return 0;
    }
};
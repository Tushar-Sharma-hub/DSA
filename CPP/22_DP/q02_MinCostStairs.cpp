// 746. Min Cost Climbing Stairs
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
// Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

//Simple Recursion- TLE Error
class Solution {
public:
    int helper(vector<int> cost,int i,int sum){
        if(i>=cost.size()) return sum;
        return min(helper(cost,i+1,sum+cost[i]),helper(cost,i+2,sum+cost[i]));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(helper(cost,0,0),helper(cost,1,0));
    }
};


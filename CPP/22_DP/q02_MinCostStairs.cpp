// 746. Min Cost Climbing Stairs
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
// Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

//Recursion plus memoization
// In this , we start from the last step and try to reach the first step. 
// We have two choices at each step, either we can take one step or two steps.
// We will take the minimum of the two choices and add the cost of the current step to it. 
// We will use a dp array to store the results of the subproblems to avoid redundant calculations.
class Solution {
public:
    int helper(vector<int>& cost,vector<int>& dp,int i){
        if(i==0 || i==1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(helper(cost,dp,i-1),helper(cost,dp,i-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(helper(cost,dp,n-1),helper(cost,dp,n-2));
    }
};

//Tabulation

// 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++){
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};
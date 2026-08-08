// Frog Jump
// Given an integer array height[] where height[i] represents the height of the i-th stair, 
// a frog starts from the first stair and wants to reach the last stair.
// From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. 
// The cost of a jump is the absolute difference in height between the two stairs.
// Determine the minimum total cost required for the frog to reach the last stair.

//Approach:
//1. We can use recursion to solve this problem by considering the two options for each stair
//2. We can use memoization to store the results of subproblems and avoid redundant calculations
//3. We can also use tabulation to solve this problem iteratively by filling up a dp array with the minimum cost for each stair.
class Solution {
public:

    int helper(vector<int>& height,vector<int>& dp, int i, int n) {
        if (i == n)
            return 0;
        if (i == n - 1)
            return abs(height[i] - height[i + 1]);
        if(dp[i]!=-1) return dp[i];
        int oneStep = abs(height[i] - height[i + 1])
                    + helper(height,dp, i + 1, n);

        int twoStep = abs(height[i] - height[i + 2])
                    + helper(height,dp, i + 2, n);
        return dp[i] = min(oneStep, twoStep);
    }

    int minCost(vector<int>& height) {

        int n = height.size() - 1;
        vector<int> dp(n+1,-1);
        return helper(height,dp,0, n);
    }
};

//Tabulation
class Solution {
public:
    int minCost(vector<int>& height) { //this is wrong because we are not considering the case when n=1
        int n = height.size() - 1;
        if (n == 0) return 0; // If there's only one stair, no cost is incurred
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        dp[n - 1] = abs(height[n] - height[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            int oneStep = abs(height[i] - height[i + 1]) + dp[i + 1];
            int twoStep = abs(height[i] - height[i + 2]) + dp[i + 2];
            dp[i] = min(oneStep, twoStep);
        }
        return dp[0];
    }
};
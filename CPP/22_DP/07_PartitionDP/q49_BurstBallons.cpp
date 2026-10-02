// 312. Burst Balloons
// You are given n balloons, indexed from 0 to n - 1. 
// Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
// If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.

// Intuition: Instead of deciding which balloon to burst first,
// consider which balloon is burst LAST in the range [i,j].
// Once it is the last one, its left and right neighbours are fixed,
// and the balloons on both sides become independent subproblems.
class Solution {
public:
    int solve(int i,int j ,vector<int>& nums,vector<vector<int>>&dp){
        // If there are no balloons left in this range
        // then there is no cost.
        if(i>j) return 0;

        // If this subproblem has already been solved,
        // return the stored answer.
        if(dp[i][j]!=-1) return dp[i][j];

        // We want the maximum coins, so initialize with
        // the smallest possible integer.
        int mincost = INT_MIN;

        // Try every balloon between i and j as the
        // LAST balloon to be burst.
        for(int indx = i;indx<=j;indx++){

            // If indx is the last balloon to burst:
            //
            // nums[i-1] -> left neighbour
            // nums[indx] -> current balloon
            // nums[j+1] -> right neighbour
            //
            // Since indx is burst last, all other balloons
            // between i and j are already removed.
            //
            // So its contribution is:
            // nums[i-1] * nums[indx] * nums[j+1]
            //
            // Then solve the left and right independent parts.
            int cost = nums[i-1]*nums[indx]*nums[j+1]
                     + solve(i,indx-1,nums,dp)
                     + solve(indx+1,j,nums,dp);

            // Take the maximum over all possible
            // choices of the last balloon.
            mincost = max(mincost,cost);
        }

        // Store the answer for range [i,j]
        // to avoid solving it again.
        return dp[i][j] = mincost;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Add 1 at the end and beginning.
        // These act as virtual boundary balloons.
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        // dp[i][j] stores the maximum coins that can be
        // obtained by bursting balloons from index i to j.
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));

        // Solve for all original balloons:
        // indices 1 to n.
        return solve(1,n,nums,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Add virtual balloons with value 1 at both ends.
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int n=nums.size();

        // dp[i][j] = maximum coins obtained by bursting
        // all balloons from index i to j.
        vector<vector<int>> dp(n, vector<int>(n,0));

        // Fill from smaller ranges to larger ranges.
        // i moves backwards because dp[i][ind-1] depends
        // on a smaller starting index.
        for(int i=n-2;i>=1;i--){
            
            // j starts from i because we are considering
            // valid ranges [i,j].
            for(int j=i;j<=n-2;j++){

                // Store the maximum coins for range [i,j].
                int maxi=0;

                // Try every balloon as the LAST balloon to burst.
                for(int ind=i;ind<=j;ind++){

                    // If ind is burst last:
                    // nums[i-1] and nums[j+1] become its neighbours.
                    //
                    // dp[i][ind-1] -> maximum coins from left part
                    // dp[ind+1][j] -> maximum coins from right part
                    int cost= nums[i-1]*nums[ind]*nums[j+1] +
                    dp[i][ind-1] + dp[ind+1][j];

                    // Take the best choice of the last balloon.
                    maxi=max(maxi,cost);
                }

                // Store the answer for range [i,j].
                dp[i][j]=maxi;
            }
        }

        // Answer for all original balloons.
        return dp[1][n-2];
    }
};
// Partitions with Given Difference - Gfg
// Given an array arr[] and an integer diff, count the number of ways to partition the array 
// into two subsets such that the difference between their sums is equal to diff.
// Note: A partition in the array means dividing an array into two subsets say S1 and S2 
// such that the union of S1 and S2 is equal to the original array and each element is present in only one of the subsets.

// Recursion + Memoization
// T.C: O(n*target) where n=arr.size()
// S.C: O(n*target) + O(n) ~ O(n*target)
// The problem can be reduced to finding the number of subsets with a given sum. 
// Let the sum of the two subsets be S1 and S2. Then, we have:
// S1 + S2 = sum(arr) = ts
// S1 - S2 = diff
// Adding the two equations, we get:
// 2*S1 = ts + diff
// S1 = (ts + diff)/2
// So, we need to find the number of subsets with sum equal to S1.
class Solution {
  public:
    int f(vector<vector<int>>& dp,int idx,vector<int>& arr,int t){
        if(idx == 0) {
            if(t == 0 && arr[0] == 0) return 2; //agr arr[0] 0 hua toh either we can take it or not the result will be same i.e t==0 so return 2 ways.
            if(t == 0 || arr[0] == t) return 1;
            return 0;
        }
        if(dp[idx][t]!=-1) return dp[idx][t];
        int notTake=f(dp,idx-1,arr,t);
        int take=0;
        if(arr[idx]<=t) take=f(dp,idx-1,arr,t-arr[idx]);
        return dp[idx][t] = take+notTake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n=arr.size();
        int ts=0;
        for(int e:arr) ts+=e;
        if((ts-diff < 0) || (ts-diff)%2!=0) return 0;
        int target = (ts-diff)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(dp,n-1,arr,target);
    }
};

//We can also use tabulation and space optimization like we did in q18 , just use the target .
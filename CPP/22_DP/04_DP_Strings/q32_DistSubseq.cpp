// 115. Distinct Subsequences
// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

//Recursion + memo
//Just use idx one for s and one for t , then if both are match either you take it or not - if taking do both idx +1 
//if not taking then idx1+1 only bcz t[idx2] is still not taken.
//if both doesn't match just inc the idx1 .
//Use dp for better t.c
class Solution {
public:
    int f(vector<vector<int>>& dp,int idx1,int idx2,string& s,string & t){
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==t[idx2]){
            int take = f(dp,idx1-1, idx2-1, s, t);
            int notTake = f(dp,idx1-1, idx2, s, t);
            return dp[idx1][idx2]=take + notTake;
        }
        return dp[idx1][idx2]=f(dp,idx1-1,idx2,s,t);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return f(dp,s.size()-1,t.size()-1,s,t);
    }
};

//Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n + 1,vector<unsigned long long>(m + 1, 0));
        // Empty t can be formed in exactly one way
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // Don't take s[i-1]
                dp[i][j] = dp[i-1][j];
                // Take s[i-1]
                if(s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
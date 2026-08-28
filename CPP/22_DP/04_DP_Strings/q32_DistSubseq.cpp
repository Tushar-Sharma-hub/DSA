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
        if(idx2>=t.size()) return 1;
        if(idx1>=s.size()) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==t[idx2]){
            int take = f(dp,idx1+1, idx2+1, s, t);
            int notTake = f(dp,idx1+1, idx2, s, t);
            return dp[idx1][idx2]=take + notTake;
        }
        return dp[idx1][idx2]=f(dp,idx1+1,idx2,s,t);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return f(dp,0,0,s,t);
    }
};
// 44. Wildcard Matching
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Recursion + memo
// Just take two idx at last of each string, if matches or p[j] is '?'
// which can match anything then it can match hence dec both idx -1
// if p[j]='*', you can either:
// 1. let '*' match the current character s[i]
//    -> i-1, j
// 2. let '*' match an empty sequence
//    -> i, j-1
class Solution {
public:
    bool f(vector<vector<int>>& dp,int i,int j,string& s,string& p){
        if(j<0 && i>=0) return false;
        if(j<0 && i<0) return true;
        if(i<0 && j>=0){
            for(int idx=0;idx<=j;idx++){
                if(p[idx]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=f(dp,i-1,j-1,s,p);
        }
        if(p[j]=='*'){
            return dp[i][j]= f(dp,i-1,j,s,p) || f(dp,i,j-1,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(dp,n1-1,n2-1,s,p);
    }
};

//Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // Empty string matches empty pattern
        dp[0][0] = 1;
        // Empty string can only match a pattern consisting entirely of '*'
        for(int j = 1; j <= n2; j++) {
            if(p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // Current characters match
                // or '?' can match any single character
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // '*' can either:
                // 1. match current character -> i-1, j
                // 2. match empty sequence   -> i, j-1
                else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};
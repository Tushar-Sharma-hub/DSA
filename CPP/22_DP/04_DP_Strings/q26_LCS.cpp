// 1143. Longest Common Subsequence
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) 
// deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

//Recursion + memo
class Solution {
public:
    int f(vector<vector<int>>& dp,int idx1,int idx2,string& text1, string& text2){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2]=1+f(dp,idx1-1,idx2-1,text1,text2);
        }
        return dp[idx1][idx2]=max(f(dp,idx1,idx2-1,text1,text2),f(dp,idx1-1,idx2,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(dp,n1-1,n2-1,text1,text2);
    }
};

//Tabulation.
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

//Space optimization.
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        if (n1 < n2) return longestCommonSubsequence(text2, text1);
        vector<int> prev(n2+1,0),curr(n2+1,0);
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n2];
    }
};

//To print LCS.
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // Backtrack from dp[n1][n2]: if characters match, add it and move diagonally; otherwise move to the adjacent 
        // cell with the larger DP value, then reverse the result.
        string lcs = "";
        int i = n1;
        int j = n2;

        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                lcs += text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());

        cout << "LCS: " << lcs << endl;

        return dp[n1][n2];
    }
};
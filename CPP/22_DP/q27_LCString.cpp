// Longest Common Substring
// Given two strings s1 and s2, determine the length of the longest substring that appears in both strings.(Consecutive)

//Tabulation
class Solution {
  public:
    int longCommSubstr(string& text1, string& text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int ans=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
};

//SO
class Solution {
  public:
    int longCommSubstr(string& text1, string& text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> prev(n2 + 1, 0);
        vector<int> curr(n2 + 1, 0);
        int ans = 0;
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return ans;
    }
};
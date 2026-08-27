// 1092. Shortest Common Supersequence 
// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
// If there are multiple valid strings, return any of them.
// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

//Just from dp of lcs , start from end and if char is matching then add that char to ans go digonal i-- j--
//else if not matching then go to max of neighbors and add that which we will not pick to ans.
class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
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
        string ans = "";
        int i = n1;
        int j = n2;
        while(i > 0 && j > 0) {
            if(text1[i-1] == text2[j-1]) {
                ans += text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += text1[i-1];
                i--;
            }
            else {
                ans += text2[j-1];
                j--;
            }
        }
        while(i > 0) {
            ans += text1[i-1];
            i--;
        }
        while(j > 0) {
            ans += text2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
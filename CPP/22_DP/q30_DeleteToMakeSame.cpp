// 583. Delete Operation for Two Strings
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.

//Just find the longest common subseq between both strings and return the reamaining ele in both string . So it can be deleted to make them same.
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
    int minDistance(string word1, string word2) {
        int n=longestCommonSubsequence(word1, word2);
        return (word1.size()-n)+(word2.size()-n);
    }
};
// 1312. Minimum Insertion Steps to Make a String Palindrome
// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

//We have to just find the biggest palindrome already on given string and for remaining element we will need that many
//elements , hence return s.size()-longestPalindromeSubseq(s);
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
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s1,s);
    }
    int minInsertions(string s) {
        int a=longestPalindromeSubseq(s);
        return s.size()-a;
    }
};
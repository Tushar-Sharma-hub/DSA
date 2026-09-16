// 1048. Longest String Chain
// You are given an array of words where each word consists of lowercase English letters.
// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA 
// without changing the order of the other characters to make it equal to wordB.
// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, 
// word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
// Return the length of the longest possible word chain with words chosen from the given list of words.

//Just sort the words based on their length and then check if the current word can be formed by 
//adding one character to any of the previous words.
//If yes then take the maximum of the length of the chain formed by the previous word and 
//update the length of the chain for the current word. Finally return the maximum length of the chain formed
class Solution {
public:
    bool check(string &s1, string &s2) {
        if (s1.size() + 1 != s2.size()) return false;
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i==s1.size();
    }
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(),nums.end(),[](string &a, string &b) {
                 return a.size() < b.size();
        });
        int n = nums.size();
        vector<int> dp(n,1);
        int mans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(check(nums[j], nums[i])){
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
            mans=max(mans,dp[i]);
        }
        return mans;
    }
};
// 32. Longest Valid Parentheses
// Given a string containing just the characters '(' and ')', 
// return the length of the longest valid (well-formed) parentheses substring.

class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0,close=0,ans=0;
        for(char e:s){
            if(e=='(') open++;
            else close++;
            if(close>open) open=close=0;
            else if(open==close) ans=max(ans,2*close);
        }
        open=close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(open>close) open=close=0;
            else if(open==close) ans=max(ans,2*open);
        }
        return ans;
    }
};
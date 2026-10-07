// 301. Remove Invalid Parentheses
// Given a string s that contains parentheses and letters, 
// remove the minimum number of invalid parentheses to make the input string valid.
// Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

//Steps:
//1. We just have to take and not take the current character and move forward.
//2. If the current character is not a parenthesis, we have to take it.
//3. If the current character is a parenthesis, we can take it or not take it and move forward, but we have to keep track of the count of open and closed parentheses(Using count)
//4. If count<0, we return because it means we have more closed parentheses than open parentheses.
//5. If we reach the end of the string and count==0, it means we have a valid string, so we check if its length is greater than the maximum length found so far(ms). 
//If it is, we clear the set and add the current string to the set. If its length is equal to ms, we just add it to the set.
class Solution {
public:
    set<string> uniq;
    int ms=0;
    void f(int i,string& cur,string& s,int count){
        if(count<0) return;
        if(i==s.size()){
            if(count==0){
                if(cur.size()>ms){
                    ms=cur.size();
                    uniq.clear();
                }
                if(cur.size()==ms){
                    uniq.insert(cur);
                }
            }
            return;
        }
        if(s[i]!='(' && s[i]!=')'){
            cur+=s[i];
            f(i+1,cur,s,count);
            cur.pop_back();
            return;
        }
        cur+=s[i];
        f(i+1,cur,s,s[i]=='('?count+1:count-1);
        cur.pop_back();
        f(i+1,cur,s,count);
    }
    vector<string> removeInvalidParentheses(string s) {
        string curr;
        f(0,curr,s,0);
        return vector<string>(uniq.begin(),uniq.end());
    }
};
// 2182. Construct String With Repeat Limit
// You are given a string s and an integer repeatLimit. 
// Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. 
// You do not have to use all characters from s.

// Return the lexicographically largest repeatLimitedString possible.

// A string a is lexicographically larger than a string b if in the first position where a and b differ, 
// string a has a letter that appears later in the alphabet than the corresponding letter in b. 
// If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(char ele:s){
            mp[ele]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto ele:mp){
            pq.push(ele);
        }
        string result="";
        while(pq.size()!=0){
            auto l=pq.top();
            pq.pop();
            int len=min(repeatLimit,l.second);
            for(int i=0;i<len;i++) result+=l.first;
            pair<char,int> sl;
            if(l.second-len>0){
                if(pq.size()!=0){
                    sl=pq.top();
                    pq.pop();
                    result+=sl.first;
                }
                else return result;
                if(sl.second-1>0) pq.push({sl.first,sl.second-1});
                pq.push({l.first,l.second-len});
            }
        }
        return result;
    }
};
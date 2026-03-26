// 767. Reorganize String
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(char ele:s) m[ele]++;
        priority_queue<pair<int,char>> q;
        for(auto temp:m){
            char c=temp.first;
            int freq=temp.second;
            q.push({freq,c});
        }
        string ans="";
        while(q.size()){
            auto temp=q.top();q.pop();
            ans+=temp.second;
            temp.first--;
            if(q.size()==0) break;
            auto t=q.top();q.pop();
            ans+=t.second;
            t.first--;
            if(temp.first!=0) q.push(temp);
            if(t.first!=0) q.push(t);
        }
        if(s.size()!=ans.size()) return "";
        return ans;
    }
};
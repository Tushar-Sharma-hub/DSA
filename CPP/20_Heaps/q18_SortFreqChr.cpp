// 451. Sort Characters By Frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ele : s){
            mp[ele]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto temp:mp){
            pq.push({temp.second,temp.first});
        }
        string ans="";
        while(pq.size()){
            auto temp=pq.top();pq.pop();
            while(temp.first){
                ans+=temp.second;
                temp.first--;
            }
        }
        return ans;
    }
};
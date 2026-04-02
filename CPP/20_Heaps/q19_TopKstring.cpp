// 692. Top K Frequent Words

class Solution {
public:
    struct Mycmp{
        bool operator()(const pair<int,string>& a,const pair<int,string>& b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string ele:words){
            mp[ele]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Mycmp> pq;
        for(auto temp:mp){
            pq.push({temp.second,temp.first});
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans(k);
        int last=k-1;
        while(pq.size()){
            ans[last]=pq.top().second;
            last--;
            pq.pop();
        }
        return ans;
    }
};
// 1636. Sort Array by Increasing Frequency
class cmp {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int ele:nums){
            mp[ele]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(auto temp:mp){
            int ele=temp.first;
            int freq=temp.second;
            pq.push({freq,ele});
        }
        while(pq.size()){
            auto temp=pq.top();
            while(temp.first!=0){
                ans.push_back(temp.second);
                temp.first--;
            }
            pq.pop();
        }
        return ans;
    }
};
// 347. Top K Frequent Elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int ele:nums){
            mp[ele]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto temp:mp){
            int ele=temp.first;
            int freq=temp.second;
            pq.push({freq,ele}); //push frequency and element in the min heap
            //min heap will take min from first and if frequency is same, then it will take min from element
            if(pq.size()>k) pq.pop(); //if the size of the min heap exceeds k, pop the top element (the least frequent element)
        }
        while(pq.size()){ //pop the top k elements from the min heap and add them to the answer
            auto temp=pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }
        return ans;
    }
};
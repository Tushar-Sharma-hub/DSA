// 658. Find K Closest Elements
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<arr.size();i++){
            int dist=abs(arr[i]-x);
            pq.push({dist,arr[i]});
            if(pq.size()>k) pq.pop(); //k se jayda elements hogy toh jo max dist pe hoga usko pop kr denge.
        }
        vector<int> ans;
        while(pq.size()){ //ab pq mai k elements h jo closest dist mai h to x.
            auto temp=pq.top();pq.pop();
            ans.push_back(temp.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
// 973. K Closest Points to Origin
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int row=points.size();
        priority_queue<pair<float,int>> pq;
        for(int i=0;i<row;i++){
            float dist=sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            pq.push({dist,i});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            auto temp=pq.top();pq.pop();
            ans.push_back(points[temp.second]);
        }
        return ans;
    }
};
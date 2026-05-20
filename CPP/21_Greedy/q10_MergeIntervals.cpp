// 56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi],
// merge all overlapping intervals, and return an array of the non-overlapping intervals that 
// cover all the intervals in the input.
bool cmp(vector<int>& a ,vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans;
        int n=intervals.size();
        ans.push_back(intervals[n-1]);
        for(int i=n-2;i>=0;i--){
            vector<int> curr=intervals[i];
            if(curr[1]>=ans[ans.size()-1][0]){
                ans[ans.size()-1][0]=min(curr[0],ans[ans.size()-1][0]);
                ans[ans.size()-1][1]=max(curr[1],ans[ans.size()-1][1]);
            }
            else{
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
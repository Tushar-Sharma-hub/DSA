// 435. Non-overlapping Intervals
// Given an array of intervals intervals where intervals[i] = [starti, endi], 
// return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.
bool cmp1(vector<int>& a,vector<int> & b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp1);
        int ans=0;
        int lst=v[0][1];
        for(int i=1;i<v.size();i++){
            if(lst>v[i][0]) ans++;
            else lst=v[i][1];
        }
        return ans;
    }
};
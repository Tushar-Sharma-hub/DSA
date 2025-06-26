//Subsets
// Print subsets of a string with unique characters.
// Follow Up: Do it for array as well
// [Leetcode - 78]
#include<iostream>
using namespace std;

void helper(vector<int>& nums,vector<int> v,vector<vector<int>>& ans,int idx){
    if(idx==nums.size()){
        ans.push_back(v);
        return;
    }
    helper(nums,v,ans,idx+1);
    v.push_back(nums[idx]);
    helper(nums,v,ans,idx+1);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> v;
    vector<vector<int>> ans;
    helper(nums,v,ans,0);
    return ans;
}
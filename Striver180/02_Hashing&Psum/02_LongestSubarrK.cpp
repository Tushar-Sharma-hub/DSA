// 178. Longest subarray with sum K
// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. 
// If no such sub-array exists, return 0.

//Time Complexity-O(n)
//Space Complexity-O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<long long, int> mp;
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                ans = i + 1;
            }
            if (mp.find(sum - k) != mp.end()) {
                ans = max(ans, i - mp[sum - k]);
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        return ans;
    }
};

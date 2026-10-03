// 1995. Count Special Quadruplets
// Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:
// nums[a] + nums[b] + nums[c] == nums[d], and
// a < b < c < d

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int c = n - 2; c >= 2; c--) {
            unordered_map<int, int> mp;
            for (int d = c + 1; d < n; d++) {
                mp[nums[d] - nums[c]]++;
            }
            for (int a = 0; a < c; a++) {
                for (int b = a + 1; b < c; b++) {
                    count+=mp[nums[a]+nums[b]];
                }
            }
        }
        return count;
    }
};
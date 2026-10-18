// 128. Longest Consecutive Sequence
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

//Time Complexity-O(n)
//Space Complexity-O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int len = 1;
                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.
// (LC-238)
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n), ans(n);
        pre[0] = 1;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        suf[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = suf[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = pre[i] * suf[i];
        }

        return ans;
    }
};

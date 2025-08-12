// 713. Subarray Product Less Than K

// Given an array of integers nums and an integer k, return the number of contiguous subarrays 
// where the product of all the elements in the subarray is strictly less than k.

#include<iostream>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int i = 0, j = 0, ans = 0;
        long long prod = 1;
        while (j < n) {
            prod *= nums[j];
            while (prod >= k && i <= j) {
                prod /= nums[i];
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};

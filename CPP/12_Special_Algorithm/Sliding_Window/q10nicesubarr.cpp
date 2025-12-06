// 1248. Count Number of Nice Subarrays

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.
#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, count = 0, ans = 0;
        while (j < n) {
            if (nums[j] % 2 != 0) {
                count++;
            }
            while (count > k) {
                if (nums[i] % 2 != 0) {
                    count--;
                }
                i++;
            }
            if (count == k) {
                int temp = i;
                while (temp < n && nums[temp] % 2 == 0) temp++;
                ans += (temp - i + 1);
            }
            j++;
        }
        return ans;
    }
};

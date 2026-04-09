// 2640. Find the Score of All Prefixes of an Array

// We define the conversion array conver of an array arr as follows:

// conver[i] = arr[i] + max(arr[0..i]) where max(arr[0..i]) is the maximum value of arr[j] over 0 <= j <= i.
// We also define the score of an array arr as the sum of the values of the conversion array of arr.

// Given a 0-indexed integer array nums of length n, return an array ans of length n where ans[i] is the score of the prefix nums[0..i].
#include<iostream>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> conv(n);
        long long maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
            conv[i] = nums[i] + maxVal;
        }
        for (int i = 1; i < n; i++) {
            conv[i] += conv[i - 1];
        }
        return conv;
    }
};

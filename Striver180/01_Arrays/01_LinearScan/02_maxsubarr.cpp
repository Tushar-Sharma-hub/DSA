// 53. Maximum Subarray
// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// Kadane's Algorithm is used to solve this problem in O(n) time complexity and O(1) space complexity.

class Solution {
public:
    //logic:
    //1.We keep track of the current sum and the maximum sum found so far.
    //2.At each step, we decide whether to add the current element to the existing subarray or start a new subarray with the current element.
    //3.We update the maximum sum found so far if the current sum exceeds it.
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        int currSum = a[0];
        int maxSum = a[0];
        for (int i=1; i<n; i++) {
            currSum = max(a[i], currSum + a[i]); 
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
// Example 1:
// Input: n = 3, k = 3
// Output: "213"
//LC-60
#include<iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        vector<int> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i;
        k = k - 1; 
        string ans = "";
        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i - 1];
            ans += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            k %= fact[i - 1];
        }
        return ans;
    }
};
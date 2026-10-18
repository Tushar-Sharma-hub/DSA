// 560. Subarray Sum Equals K
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

//Time Complexity-O(n)
//Space Complexity-O(n)
//Approach-1: Using prefix sum and hashing
//1. Create a prefix sum array of the given array.
//2. Create a hash map to store the frequency of prefix sums.
//3. Iterate through the prefix sum array and for each element, check if the difference between the current prefix sum and k exists in the hash map. If it does, add the frequency of that prefix sum to the answer.
//4. Update the frequency of the current prefix sum in the hash map.
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int prefix[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (prefix[i] == k) ans++;
            if (mp.find(prefix[i] - k) != mp.end()) {
                ans += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }

        return ans;
    }
};

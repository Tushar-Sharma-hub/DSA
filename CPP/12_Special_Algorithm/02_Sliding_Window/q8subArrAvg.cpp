// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

// Given an array of integers arr and two integers k and threshold, 
// return the number of sub-arrays of size k and average greater than or equal to threshold.

#include<iostream>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i = 0, j = k - 1;
        int sum = 0, count = 0;
        for (int a = 0; a < k; a++) {
            sum += arr[a];
        }
        while (j < n) {
            if (sum / k >= threshold) {
                count++;
            }
            j++;
            if (j < n) {
                sum = sum + arr[j] - arr[i];
                i++;
            }
        }
        return count;
    }
};
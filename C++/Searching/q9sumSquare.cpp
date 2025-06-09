// 633. Sum of Square Numbers
// Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.
// Example 1:
// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
#include<iostream>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0;
        long long high = (long long)sqrt(c);
        while (low <= high) {
            long long sum = low * low + high * high;
            if (sum == c) return true;
            else if (sum < c) low++;
            else high--;
        }
        return false;
    }
};
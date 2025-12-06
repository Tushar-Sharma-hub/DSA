// 1390. Four Divisors
// Given an integer array nums, 
// return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.
#include<iostream>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            vector<int> divisors;
            for (int d = 1; d * d <= num; d++) {
                if (num % d == 0) {
                    divisors.push_back(d);
                    if (d != num / d) divisors.push_back(num / d);
                }
            }
            if (divisors.size() == 4) {
                for (int d : divisors) sum += d;
            }
        }
        return sum;
    }
};

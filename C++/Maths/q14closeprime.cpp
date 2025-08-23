// 2523. Closest Prime Numbers in Range

// Given two positive integers left and right, find the two integers num1 and num2 such that:

// left <= num1 < num2 <= right .
// Both num1 and num2 are prime numbers.
// num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
// Return the positive integer array ans = [num1, num2]. If there are multiple pairs 
// satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int prev = -1;
        int num1 = -1, num2 = -1;
        int minDiff = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                if (prev != -1) {
                    int diff = i - prev;
                    if (diff < minDiff) {
                        minDiff = diff;
                        num1 = prev;
                        num2 = i;
                    }
                }
                prev = i;
            }
        }
        if (num1 == -1) return {-1, -1};
        return {num1, num2};
    }
};

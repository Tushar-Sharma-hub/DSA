// 2761. Prime Pairs With Target Sum
// You are given an integer n. We say that two integers x and y form a prime number pair if:
// 1 <= x <= y <= n
// x + y == n
// x and y are prime numbers
// Return the 2D sorted list of prime number pairs [xi, yi]. 
// The list should be sorted in increasing order of xi. If there are no prime number pairs at all, return an empty array.
// Note: A prime number is a natural number greater than 1 with only two factors, itself and 1.
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if (n <= 2) return {};
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                int prod = i * i;
                while (prod <= n) {
                    isPrime[prod] = false;
                    prod += i;
                }
            }
        }
        vector<vector<int>> v;
        for(int i=2;i<=n/2;i++){
            if(isPrime[i] && isPrime[n-i]) v.push_back({i,n-i});
        }
        return v;
    }
};
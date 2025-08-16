// 204. Count Primes
// Given an integer n, return the number of prime numbers that are strictly less than n.
#include<iostream>
using namespace std;

//Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> v(n + 1);
        for (int i = 0; i <= n; i++) {
            v[i] = i;
        }
        v[0] = v[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (v[i] != 0) {
                int prod = i * i; //Set 0 inplace of prod of prime.
                while (prod <= n) {
                    v[prod] = 0; //setting composite no. to 0.
                    prod += i;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (v[i] != 0) count++;
        }
        return count;
    }
};
// 204. Count Primes
// Given an integer n, return the number of prime numbers that are strictly less than n.
#include<iostream>
using namespace std;

//Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                int prod = i * i;  // start from i*i
                while (prod <= n) {
                    isPrime[prod] = false;
                    prod += i;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};

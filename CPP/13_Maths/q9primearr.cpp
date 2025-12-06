// 1175. Prime Arrangements

// Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)

// (Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of 
// two positive integers both smaller than it.)

// Since the answer may be large, return the answer modulo 10^9 + 7.
#include<iostream>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long factorial(int n) {
        long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = (fact * i) % MOD;
        }
        return fact;
    }
    int numPrimeArrangements(int n) {
        vector<bool> isprime(n+1,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                int j=i*i;
                while(j<=n){
                    isprime[j]=false;
                    j+=i;
                }
            }
        }
        int p=0;
        for(int i=2;i<isprime.size();i++){
            if(isprime[i]) p++;
        }
        long long result=factorial(p)*factorial(n-p)%MOD;
        return result;
    }
};
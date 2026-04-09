// 2521. Distinct Prime Factors of Product of Array

// Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.

// A number greater than 1 is called prime if it is divisible by only 1 and itself.
// An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.
#include<iostream>
using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxi + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxi; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxi; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for(int i=0;i<isPrime.size();i++){
            if(isPrime[i]) primes.push_back(i);
        }
        vector<int> taken(primes.size(),0);
        int idx=0;
        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            for(int j=0;j<primes.size();j++){
                if(primes[j]>ele) break;
                if(ele%primes[j]==0) taken[j]=1;
            }
        }
        int count=0;
        for(int i=0;i<taken.size();i++){
            if(taken[i]==1) count++;
        }
        return count;
    }
};

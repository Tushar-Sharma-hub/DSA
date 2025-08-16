// 2614. Prime In Diagonal

// You are given a 0-indexed two-dimensional integer array nums.

// Return the largest prime number that lies on at least one of the diagonals of nums. In case, no prime is present on any of the diagonals, return 0.

// Note that:

// An integer is prime if it is greater than 1 and has no positive integer divisors other than 1 and itself.
// An integer val is on one of the diagonals of nums if there exists an integer i for which nums[i][i] = val or an i 
// for which nums[i][nums.length - i - 1] = val.
#include<iostream>
using namespace std;

class Solution {
public:
    bool isprime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){ // we will go till sqrt(n) to save time.
            if(n%i==0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();
        int maxprime=0;
        for(int i=0;i<n;i++){
            if(isprime(nums[i][i])){
                maxprime=max(maxprime,nums[i][i]);
            }
            if(isprime(nums[i][n-i-1])){
                maxprime=max(maxprime,nums[i][n-i-1]);
            }
        }
        return maxprime;
    }
};
// 3115. Maximum Prime Difference

// You are given an integer array nums.

// Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.
#include<iostream>
using namespace std;

class Solution {
public:
    bool isprime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        int left=-1,right=0;
        for(int i=0;i<n;i++){
            if(isprime(nums[i])){
                left=i;
                break;
            }
        }
        if(left==-1) return 0;
        for(int j=n-1;j>=0;j--){
            if(isprime(nums[j])){
                right=j;
                break;
            }
        }
        if(right==left) return 0;
        return right-left;
    }
};
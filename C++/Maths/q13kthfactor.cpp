// 1492. The kth Factor of n

// You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

// Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.
#include<iostream>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                v.push_back(i);
                if(i!=(n/i)) v.push_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        if(v.size()<k) return -1;
        return v[k-1];
    }
};
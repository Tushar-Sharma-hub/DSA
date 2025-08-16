// 507. Perfect Number

// A perfect number is a positive integer that is equal to the sum of its positive divisors, 
// excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

// Given an integer n, return true if n is a perfect number, otherwise return false.
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1;i<sqrt(num);i++){
            if(num%i==0 && i!=num) sum+=i;
        }
        for(int i=sqrt(num);i>=1;i--){
            if(num%i==0 && num/i!=num) sum+=num/i;
        }
        if(sum==num) return true;
        return false;
    }
};
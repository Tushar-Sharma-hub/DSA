//Sqrt(x) LC-69
#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid*mid==x) return mid; //We can use long long for multiplying mid as it can bea big number.
            else if(mid*mid<x) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
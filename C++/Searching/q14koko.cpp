//875. Koko Eating Bananas
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.
#include<iostream>
using namespace std;

class Solution {
public:
    bool check(vector<int> & piles,int speed,int h){
        int n=piles.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(count>h) return false;
            if(speed>=piles[i]) count++;
            else{
                if(piles[i]%speed==0) count+=piles[i]/speed;
                else{
                    count+=piles[i]/speed + 1;
                } 
            }
        }
        if(count>h) return false;
        else return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>max) max=piles[i];
        }
        int low=1,high=max;
        int k=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(piles,mid,h)){
                k=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return k;
    }
};
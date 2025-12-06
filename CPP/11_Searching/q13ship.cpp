//1011. Capacity To Ship Packages Within D Days
// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. 
// Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
// We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

#include<iostream>
using namespace std;

class Solution {
public:
    bool check(int mid,vector<int>& weights,int days){
        int n=weights.size();
        int m=mid;//currrent capacity.
        int count=1;//number of days for particular capacticy(m).
        for(int i=0;i<n;i++){
            if(m>=weights[i]){
                m-=weights[i];
            }
            else{
                count++; //day finished
                m=mid;//reset current capacity
                m-=weights[i];//antoher day starts
            }
        }
        if(count>days) return false;
        else return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int max=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            if(weights[i]>max) max=weights[i];
            sum+=weights[i];
        }
        int low=max; //the lowest capcity of ship willbe the maximum weight in the array.
        int high=sum; // the larget capacity of the ship will be the sum .
        int minCapacity=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,weights,days)){
                minCapacity=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return minCapacity;
    }
};
//LC-2187
// You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

// Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. 
//Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

// You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
//Return the minimum time required for all buses to complete at least totalTrips trips.
#include<iostream>
using namespace std;

class Solution {
public:
    bool check(long long mid,vector<int>& time,int totalTrips){
        long long trips=0;
        int n=time.size();
        for(int i=0;i<n;i++){
            trips+=mid/(long long)time[i];
        }
        if(trips<totalTrips) return false;
        else return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        int mx=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,time[i]);
        }
        long long low=1;
        long long high=(long long)mx*(long long)totalTrips;
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid,time,totalTrips)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
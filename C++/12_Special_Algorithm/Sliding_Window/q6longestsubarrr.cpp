// 1493. Longest Subarray of 1's After Deleting One Element

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
#include<iostream>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int k=1;
        int i=0,j=0,len=INT_MIN,maxlen=INT_MIN,flips=0;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<k){
                    flips++;
                    j++;
                }
                else{
                    len=j-i;
                    maxlen=max(maxlen,len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
        len=j-i;
        maxlen=max(maxlen,len);
        return maxlen-1;
    }
};
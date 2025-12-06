//Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
//LC-169
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    return nums[(n/2)];
}
//as major element will be more than n/2 so it will cover atleast half of the array hence the middle element will be the majority element.
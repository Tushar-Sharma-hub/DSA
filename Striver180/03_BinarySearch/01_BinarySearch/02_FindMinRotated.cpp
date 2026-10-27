// 153. Find Minimum in Rotated Sorted Array
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX;
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else if(nums[mid]<nums[low]){
                high=mid;
                low++;
            }
            else high--;
        }
        return nums[low];
    }
};
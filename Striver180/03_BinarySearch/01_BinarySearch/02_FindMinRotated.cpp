// 153. Find Minimum in Rotated Sorted Array
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=nums[0];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[low]){
                ans=min(ans,nums[mid]);
                high=mid-1;
            }else{
                ans=min(ans,nums[low]);
                low=mid+1;
            }
        }
        return ans;
    }
};
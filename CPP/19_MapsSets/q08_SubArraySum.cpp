// 560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> mp;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k) count++;
            int rem=nums[i]-k;
            if(mp.find(rem)!=mp.end()) count+=mp[rem];
            mp[nums[i]]++;
        }
        return count;
    }
};
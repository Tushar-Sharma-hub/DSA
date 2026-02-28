class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            int rem=target-ele;
            if(m.find(rem)!=m.end()){
                return {m[rem],i};
            }
            else m[ele]=i;
        }
        return {};
    }
};
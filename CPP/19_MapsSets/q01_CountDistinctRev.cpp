// 2442. Count Number of Distinct Integers After Reverse Operations
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int ele:nums){
            s.insert(ele);
            int rev=0;
            while(ele!=0){
                rev*=10;
                rev+=ele%10;
                ele/=10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};
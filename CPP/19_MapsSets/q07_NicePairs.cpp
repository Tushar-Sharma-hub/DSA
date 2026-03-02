// 1814. Count Nice Pairs in an Array
class Solution {
public:
    long long rev(long long n){
        long long rev=0;
        while(n!=0){
            rev*=10;
            rev+=n%10;
            n/=10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<long long,long long> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]-rev(nums[i])]++;
        }
        int ans=0;
        for(auto p:m){
            long long k = p.second;
            long long pairs = (k * (k - 1) / 2) % MOD;
            ans = (ans + pairs) % MOD;
        }
        return ans;
    }
}; 
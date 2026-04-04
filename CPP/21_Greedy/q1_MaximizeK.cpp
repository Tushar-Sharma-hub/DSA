// 1005. Maximize Sum Of Array After K Negations

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        int sum=0;
        for(int ele:nums) sum+=ele;
        while(k--){
            int el=pq.top();
            if(el==0) break;
            pq.pop();
            sum-=el;
            pq.push(-1*el);
            sum+=(-1*el);
        }
        return sum;
    }
};
// You are given an integer array nums of length n, and an integer array queries of length m.

// Return an array answer of length m where answer[i] is the maximum size of a subsequence 
// that you can take from nums such that the sum of its elements is less than or equal to queries[i].

// A subsequence is an array that can be derived from another array by deleting some or no elements 
// without changing the order of the remaining elements.
#include<iostream>
using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n=nums.size();
    int m=queries.size();
    sort(nums.begin(),nums.end());
    for(int i=1;i<n;i++){
        nums[i]=nums[i-1]+nums[i];
    }
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        int len=0,low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>queries[i]) high=mid-1;
            else{
                len=mid+1;
                low=mid+1;
            }
        }
        ans[i]=len;
    }
    return ans;
}

int main(){
    vector<int> nums={4,5,2,1};
    vector<int> queries={3,10,21};
    vector<int> ans=answerQueries(nums,queries);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

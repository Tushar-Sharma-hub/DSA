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
    vector<int> pre(n);
    pre[0]=nums[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+nums[i];
    }
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        int idx=0;
        for(int j=0;j<n;j++){
            if(pre[j]>queries[i]){
                if(j==0) break;
                else{
                    idx=j;
                    break;
                }
            }
            if(pre[j]==queries[i]){
                idx=j+1;
                break;
            }
        }
        ans.push_back(idx);
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

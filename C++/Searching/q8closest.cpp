// 658. Find K Closest Elements

// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
// The result should also be sorted in ascending order.
// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3

// Output: [1,2,3,4]
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> ans(k);
        //x is target 
        //if x is less than first element than just return first k elements.
        if(x<arr[0]){
            for(int i=0;i<k;i++){
                ans[i]=arr[i];
            }
            return ans;
        }
        //if x is more than last element than just return last k elements.
        else if(x>arr[n-1]){
            int i=n-1;
            int j=k-1;
            while(j>=0){
                ans[j]=arr[i];
                i--;
                j--;
            }
            return ans;
        }
        //to find number if both above if conditions don't execute.
        int low=0,high=n-1,flag=0,mid=-1;
        int t=0;//index of ans.
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid]==x){
                flag=1;
                ans[t]=arr[mid]; //as number itself is closest to itself.
                t++;
                break;
            }
            else if(arr[mid]>x) high=mid-1;
            else low=mid+1;
        }
        //if element not found then lower bound and upper bound will be:
        int lb=high;//After BS high always points to lb if element not found.
        int ub=low;////After BS low always points to ub if element not found.
        //if found:
        if(flag==1){
            lb=mid-1;
            ub=mid+1;
        }
        while(t<k && lb>=0 && ub<=n-1){
            int d1=abs(x-arr[lb]);
            int d2=abs(x-arr[ub]);
            if(d1<=d2){ //check closest
                ans[t]=arr[lb]; //push closest in ans;
                lb--;
            }
            else{
                ans[t]=arr[ub];
                ub++;
            }
            t++;
        }
        if(lb<0){//if lb gets less than 0 and k is still not full filled than puts remaining also.
            while(t<k){
                ans[t]=arr[ub];
                ub++;
                t++;
            }
        }
        if(ub>=n){//if ub gets more than n-1 and k is still not full filled than puts remaining also.
            while(t<k){
                ans[t]=arr[lb];
                lb--;
                t++;
            }
        }
        sort(ans.begin(),ans.end()); //at last sort as we have pushed element in ans in non-sorted way.
        return ans;
    }
};  
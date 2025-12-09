// 239. Sliding Window Maximum
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array 
// to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> ngi(n);
        stack<int> temp;
        ngi[n-1]=n;
        temp.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(temp.size()!=0 && arr[temp.top()]<arr[i]) temp.pop();
            if(temp.size()==0) ngi[i]=n;
            else ngi[i]=temp.top();
            temp.push(i);
        }
        vector<int> ans;
        int j=0;
        for(int i=0;i<n-k+1;i++){
            if(j<i) j=i;
            int mx=arr[i];
            while(j<i+k){
                mx=arr[j];
                if(ngi[j]>=i+k) break;
                j=ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
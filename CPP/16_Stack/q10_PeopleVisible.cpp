// 1944. Number of Visible People in a Queue
// There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. 
// You are given an array heights of distinct integers where heights[i] represents the height of the ith person.
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n,0);
        stack<int> temp;
        ans[n-1]=0;
        temp.push(heights[n-1]);
        for(int i=n-2;i>=0;i--){
            int count=0;
            while(temp.size()>0 && temp.top()<=heights[i]){
                temp.pop();
                count++;
            }
            if(temp.size()==0) ans[i]=count;
            else ans[i]=count+1;
            temp.push(heights[i]);
        }
        return ans;
    }
};
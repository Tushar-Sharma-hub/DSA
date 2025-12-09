// 84. Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
// return the area of the largest rectangle in the histogram.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nsi(n);
        vector<int> psi(n);

        stack<int> temp;
        nsi[n-1]=n;
        temp.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(temp.size()!=0 && heights[temp.top()]>=heights[i]) temp.pop();
            if(temp.size()==0) nsi[i]=n;
            else nsi[i]=temp.top();
            temp.push(i);
        }

        stack<int> temp1;
        psi[0]=-1;
        temp1.push(0);
        for(int i=1;i<n;i++){
            while(temp1.size()!=0 && heights[temp1.top()]>=heights[i]) temp1.pop();
            if(temp1.size()==0) psi[i]=-1;
            else psi[i]=temp1.top();
            temp1.push(i);
        }

        int maxans=0;
        for(int i=0;i<n;i++){
            int height=heights[i];
            int breadth=nsi[i]-psi[i]-1;
            int ans=height*breadth;
            maxans=max(ans,maxans);
        }
        return maxans;
    }
};
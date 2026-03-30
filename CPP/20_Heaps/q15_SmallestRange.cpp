// 632. Smallest Range Covering Elements from K Lists

// You have k lists of sorted integers in non-decreasing order. 
// Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

// dekh hum k lists ke first element ko min heap mai daal denge , or max variable maintain krenge jo ki max element ko store krega , 
// ab hum min heap se top nikalenge or uske next element ko min heap mai daal denge , or max variable ko update krenge , 
// ab har baar jab hum min heap se top nikalenge toh hum check krenge ki kya current range (max-min) chota h ya nhi , 
// agar chota h toh answer update krenge , or is process ko tab tak repeat krenge jab tak kisi list ke sare elements exhaust nhi ho jate.
class Solution {
public:
    typedef pair<int,pair<int,int>> pip; //{val,{row,col}}
    vector<int> smallestRange(vector<vector<int>>& arr) {
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        int mx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mx=max(mx,arr[i][0]);
            pq.push({arr[i][0],{i,0}});
        }
        int mn=pq.top().first;
        int start=mn,end=mx;
        while(true){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col==arr[row].size()-1) break;
            pq.push({arr[row][col+1],{row,col+1}});
            mx=max(mx,arr[row][col+1]);
            mn=pq.top().first;
            if(mx-mn<end-start){
                start=mn;end=mx;
            }
        }
        return {start,end};
    }
};
// 1675. Minimize Deviation in Array
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> mxh;
        int mine=INT_MAX;
        for(int ele:nums){ //odd elements ko ek baar double kr denge taki wo even ho jaye , or even elements ko waise hi rakh denge , or saath hi minimum element ko update krte jayenge
            if(ele%2!=0) ele*=2;
            if(mine>ele) mine=ele;
            mxh.push(ele);
        }
        int ans=abs(mxh.top()-mine); //ab hum max element ko continuously divide by 2 krte jayenge jab tak wo even h , or har baar minimum element ko update krte jayenge , or answer ko update krte jayenge
        while(mxh.top()%2==0){
            int temp=mxh.top();mxh.pop();
            if(ans>abs(temp-mine)) ans=abs(temp-mine);
            temp/=2;
            if(temp<mine) mine=temp;
            mxh.push(temp);
            ans = min(ans, mxh.top() - mine);
        }
        return ans;
    }
};
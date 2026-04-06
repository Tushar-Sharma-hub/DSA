// 1710. Maximum Units on a Truck

class Solution {
public:
    static bool cmp(vector<int> & v1,vector<int> & v2){
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        //T.C:O(NlogN)
        sort(arr.begin(),arr.end(),cmp);
        double profit=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]<=truckSize){
                profit+=(arr[i][0]*arr[i][1]);
                truckSize-=arr[i][0];
            }
            else{
                profit+=(truckSize*arr[i][1]);
                break;
            }
        }
        return profit; 
    }
};
// 786. K-th Smallest Prime Fraction
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>p;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double a=(double)arr[i]/arr[j]; //fraction and uski value push krri
                p.push({a,{arr[i],arr[j]}});
                if(p.size()>k) p.pop(); //k se zyada elements push krne par top element pop kr denge , kyuki max heap hai toh largest fraction pop hoga , or end mai top element k-th smallest fraction hoga
            }
        }
        vector<int>ans;
        ans.push_back(p.top().second.first);
        ans.push_back(p.top().second.second);
        return ans;
    }
};
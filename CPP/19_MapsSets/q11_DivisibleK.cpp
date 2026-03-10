// 1497. Check If Array Pairs Are Divisible by k
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            arr[i]=((arr[i]%k)+k)%k; //for negative numbers, we need to add k to get the correct remainder
            m[arr[i]]++;
        }
        if(m.find(0)!=m.end()){
            if(m[0]%2!=0) return false;
            m.erase(0);
        }
        for(auto ele:m){
            int temp=k-ele.first;
            if(m.find(temp)==m.end()) return false;
            else{
                if(m[temp]!=m[ele.first]) return false;
            }
        }
        return true;
    }
};
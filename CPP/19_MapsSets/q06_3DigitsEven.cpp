// 2094. Finding 3-Digit Even Numbers
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int ele:digits){
            m[ele]++;
        }
        for(int i=100;i<=999;i++){
            int x=i;
            int three=x%10;
            x/=10;
            int two=x%10;
            x/=10;
            int one=x;
            if(three%2==0){
                if(m.find(three)!=m.end()){
                    m[three]--;
                }
                else continue;
                if(m.find(two)!=m.end() && m[two]!=0){
                    m[two]--;
                }
                else {
                    m[three]++; 
                    continue;
                }
                if(m.find(one)!=m.end() && m[one]!=0){
                    m[one]--;
                }
                else {
                    m[three]++;
                    m[two]++;
                    continue;
                }
                ans.push_back(i);
                m[three]++;
                m[two]++;
                m[one]++;
            }
            else continue;
        }
        return ans;
    }
};
// 1207. Unique Number of Occurrences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int ele:arr){
            m[ele]++;
        }
        unordered_set<int> s;
        for(auto p:m){
            s.insert(p.second);
        }
        if(m.size()!=s.size()) return false;
        return true;
    }
};
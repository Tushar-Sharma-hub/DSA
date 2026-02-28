// 1207. Unique Number of Occurrences
// Given an array of integers arr, return true if the number of occurrences of
// each value in the array is unique or false otherwise.
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
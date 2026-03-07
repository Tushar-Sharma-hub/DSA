//49. Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp; // sorted string, list of anagrams
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end()); // sort the string to get the same key for anagrams
            if(mp.find(s)==mp.end()){ // if the sorted string is not in the map, create a new entry
                vector<string> v;
                v.push_back(strs[i]); // add the original string to the list of anagrams
                mp[s]=v;
            }
            else{ // if the sorted string is already in the map, add the original string to the list of anagrams
                mp[s].push_back(strs[i]);
            }
        }
        for(auto x:mp){
            ans.push_back(x.second); // add the list of anagrams to the answer
        }
        return ans;
    }
};
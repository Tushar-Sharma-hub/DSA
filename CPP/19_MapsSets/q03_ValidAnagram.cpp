// 242. Valid Anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++; //It will create a new key if s[i] is not present in m, and update the value of key s[i] by 1
        }
        for(int i=0;i<t.size();i++){
            if(m.find(t[i])!=m.end()){
                m[t[i]]--; //It will update the value of key t[i] by -1
                if(m[t[i]]==0) m.erase(t[i]); //It will erase the key t[i] from m if the value of key t[i] is 0
            }
            else return false; //It will return false if t[i] is not present in m, which means t[i] is not present in s, so s and t are not anagrams of each other
        }
        if(m.size()==0) return true; //It will return true if m is empty, which means all the characters of s are present in t and all the characters of t are present in s, so s and t are anagrams of each other
        return false;
    }
};
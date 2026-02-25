// 2744. Find Maximum Number of String Pairs
// You are given a 0-indexed array words consisting of distinct strings.

// The string words[i] can be paired with the string words[j] if:

// The string words[i] is equal to the reversed string of words[j].
// 0 <= i < j < words.length.
// Return the maximum number of pairs that can be formed from the array words.
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int ans=0;
        for(string ele:words){
            string rev=ele;
            reverse(rev.begin(),rev.end());
            if(s.find(rev)!=s.end()) ans++;
            else s.insert(ele);
        }
        return ans;
    }
};
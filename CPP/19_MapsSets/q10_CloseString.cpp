// 1657. Determine if Two Strings Are Close

//1st Method (Using HashMap):
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(int i=0;i<word1.size();i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        for(auto ele:word2){
            if(m1.find(ele)==m1.end()) return false;
        }
        map<int,int> c1;
        map<int,int> c2;
        for(auto ele:m1){
            c1[ele.second]++;
        }
        for(auto ele:m2){
            c2[ele.second]++;
        }
        if(c1==c2) return true;
        return false;
    }
};
//2nd Method (Using Frequency Array):
bool closeStrings(string w1, string w2) {
    if(w1.size()!=w2.size()) return false;

    vector<int> f1(26,0), f2(26,0);

    for(char c:w1) f1[c-'a']++;
    for(char c:w2) f2[c-'a']++;

    for(int i=0;i<26;i++){
        if((f1[i]==0)!=(f2[i]==0)) return false;
    }

    sort(f1.begin(),f1.end());
    sort(f2.begin(),f2.end());

    return f1==f2;
}
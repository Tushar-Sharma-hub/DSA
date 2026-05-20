// 781. Rabbits in Forest
// "How many other rabbits have the same color as you?" 

//intuition: if a rabbit says x, then there are x+1 rabbits of the same color. 
//so we can group them in groups of x+1 and count the number of groups and add to the answer. 
//if there are less than x+1 rabbits, then we can just add x+1 to the answer because there must be at least x+1 rabbits of that color.
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int ele:answers){
            mp[ele]++;
        }
        int ans=0;
        for(auto temp:mp){
            while(temp.first+1<temp.second){
                ans+=temp.first+1;
                temp.second-=temp.first+1;
            }
            ans+=temp.first+1;
        }
        return ans;
    }
};
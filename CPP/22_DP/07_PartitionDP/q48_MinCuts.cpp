// 1547. Minimum Cost to Cut a Stick
// Given a wooden stick of length n units. The stick is labelled from 0 to n. 
// For example, a stick of length 6 is labelled as follows:
// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
// You should perform the cuts in order, you can change the order of the cuts as you wish.
// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. 
// When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). 
// Please refer to the first example for a better explanation.
// Return the minimum total cost of the cuts.

class Solution {
public:
    int f(vector<vector<int>>& dp,int i,int j,vector<int>& cuts){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int idx=i;idx<=j;idx++){
            int ans=cuts[j+1]-cuts[i-1]+f(dp,i,idx-1,cuts)+f(dp,idx+1,j,cuts);
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return f(dp,1,c,cuts);
    }
};

class Solution {
public:
    int minCost(int n,vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
                int mini=INT_MAX;
                for(int ind=i;ind<=j;ind++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};
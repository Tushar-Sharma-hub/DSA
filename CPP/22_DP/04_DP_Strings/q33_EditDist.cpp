// 72. Edit Distance
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

// Recursion + memo
class Solution {
public:
    int f(vector<vector<int>>& dp,int i,int j,string& w1,string& w2){
        if(i<0) return j+1; //w1 is exhausted/empty then steps to make w1=w2 is j+1 insertion in w2.
        if(j<0) return i+1; //w2 is exhausted/empty then steps to make w1=w2 is i+1 deletion if w1.
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]){
            return dp[i][j]=f(dp,i-1,j-1,w1,w2);
        }
        return dp[i][j]=1+min(f(dp,i,j-1,w1,w2),min(f(dp,i-1,j,w1,w2),f(dp,i-1,j-1,w1,w2)));
        // insertion -> i,j-1
        // delete -> i-1,j
        // replace -> i-1,j-1
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(dp,n1-1,n2-1,word1,word2);
    }
};

//Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        if(n1==0) return n2;
        if(n2==0) return n1;
        //here we are comparing it 
        for(int i=0;i<=n2;i++){ //to make word1 with idx=0(hence empty) we need ith step.So just fill the dp.
            dp[0][i]=i;
        }
        for(int i=0;i<=n1;i++){ //to make w2 with idx=0(hence empty w2) we need to delete word1 all ele to make it empty , So just fill the dp.
            dp[i][0]=i;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n1][n2];
    }
};

//Space Optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<int> prev(n2+1,0),curr(n2+1,0);
        if(n1==0) return n2;
        if(n2==0) return n1;
        for(int i=0;i<=n2;i++){
            prev[i]=i;
        }
        for(int i=1;i<=n1;i++){
            curr[0]=i;
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }else{
                    curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
                }
            }
            prev=curr;
        }
        return prev[n2];
    }
};
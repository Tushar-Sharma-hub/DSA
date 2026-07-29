// 547. Number of Provinces
// There are n cities. Some of them are connected, while some are not.
// If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 
// if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,vector<int>& vis){
        vis[i]=true;
        for(int j=0;j<adj.size();j++){
            if(adj[i][j]==1 && !vis[j]){
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
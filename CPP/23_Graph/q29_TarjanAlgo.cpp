//Bridge is an edges in a graph when removed increases the number of connected components in the graph.
//We find bridges in the graph using Tarjan's algo.

// 1192. Critical Connections in a Network
// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network 
// where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers 
// directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<int>& vis,vector<int> adj[],int tin[],int low[],vector<vector<int>> & ans){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto v:adj[node]){
            if(v==parent) continue;
            if(vis[v]==0){
                dfs(v,node,vis,adj,tin,low,ans);
                low[node]=min(low[node],low[v]);
                if(low[v]>tin[node]){
                    ans.push_back({v,node});
                }
            }
            else{
                low[node] = min(low[node],low[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        dfs(0,-1,vis,adj,tin,low,ans);
        return ans;
    }
};
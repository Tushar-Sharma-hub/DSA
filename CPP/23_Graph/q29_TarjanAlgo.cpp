//Bridge is an edges in a graph when removed increases the number of connected components in the graph.
//We find bridges in the graph using Tarjan's algo.

// 1192. Critical Connections in a Network
// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network 
// where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers 
// directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

//Approach: We will use Tarjan's algorithm to find bridges in the graph. We will maintain two arrays tin and low.
//1. tin[node] will store the time of first visit of the node in dfs.
//2. low[node] will store the lowest time of visit of the node or any of its descendants in dfs.Not parent of node.
//3. Timer will be used to keep track of the time of visit of the nodes in dfs.
//4. If low[v]>tin[node] then the edge (node,v) is a bridge in the graph because it means that there is no back edge from v or any of its descendants to node or any of its ancestors in dfs tree.
//5. We will use a vector of vectors to store the bridges in the graph and return it as the answer.
//T.C= O(V+E) S.C=O(V+E)
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
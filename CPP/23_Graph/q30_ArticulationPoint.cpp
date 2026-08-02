// Articulation Point
// Given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], 
// where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v. 
// Return all the articulation points (or cut vertices) in the graph. An articulation point is a vertex whose removal, 
// along with all its connected edges, increases the number of connected components in the graph. 
// The given graph may be disconnected, i.e., it may consist of more than one connected component. 
// If no such point exists, return {-1}.

//Same as Tarjan's algorithm for finding bridges, we can use a similar approach to find articulation points in the graph.

class Solution {
  public:
    int timer=0;
    void dfs(int node,int parent,vector<int> adj[],vector<int>& vis,int tin[],int low[],vector<int>& mark){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        int child=0; //for first node we need to check if it has more than 1 child in dfs tree then it is an articulation point.
        for(int v:adj[node]){
            if(v==parent) continue;
            if(vis[v]==0){
                dfs(v,node,adj,vis,tin,low,mark);
                low[node]=min(low[node],low[v]);
                if(low[v]>=tin[node] && parent!=-1) mark[node]=1;
                child++;
            }else{
                low[node]=min(low[node],tin[v]);
            }
        }
        if(child>1 && parent==-1) mark[node]=1; //if root node has more than 1 child and it has no parent(first node) then it is an articulation point.
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(V,0);
        int tin[V];
        int low[V];
        vector<int> mark(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,tin,low,mark);
            }
        }
        vector<int> ans;
        for(int i=0;i<mark.size();i++){
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};
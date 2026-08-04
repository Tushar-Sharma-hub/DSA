//Striongly Connected Components in a directed graph using Kosaraju's Algorithm

//1.Sort all the edges according to their finishing times in decreasing order.
//2.Reverse the graph.
//3.Do DFS according to the order of sorted edges and print the number of strongly connected components.

class Solution {
  public:
    void dfs(int node,vector<int>& vis,vector<int> adj[],stack<int>& st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    void dfs3(int node,vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs3(it,vis,adj);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        while(st.size()>0){
            int node=st.top();st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node,vis,adjT);
            }
        }
        return scc;
    }
};
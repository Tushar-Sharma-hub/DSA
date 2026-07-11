//Topolofical Sorting
//It is only possible for Directed Acyclic Graph(DAG).
//Linear ordering of vertices such that for every directed edge u->v, vertex u comes before v in the ordering.
//It is used to solve dependency problems like task scheduling, course prerequisite problems, etc. 

//Using Stack - DFS
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj,vector<bool>& visited,stack<int>& st) {
        visited[node] = true;
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<vector<int>> adj(V);
       for(auto it : edges){
           adj[it[0]].push_back(it[1]);
       }
       vector<bool> visited(V,false);
       stack<int> st;
       for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,adj,visited,st);
           }
       }
       vector<int> result;
       while(!st.empty()){
           result.push_back(st.top());
           st.pop();
       }
       return result;
    }
};
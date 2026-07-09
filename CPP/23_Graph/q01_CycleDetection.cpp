// Undirected Graph Cycle
// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], 
// where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
// Note: The graph can have multiple component.
//T.C: O(V+E) S.C: O(V+E)

//Using DFS
class Solution {
  public:
    bool cyc(vector<vector<int>>& ver,vector<bool>& visited,int par,int v){
        visited[v]=true;
        for(int i:ver[v]){
            if(!visited[i]){
                if(cyc(ver,visited,v,i)) return true;
            }
            else if(i!=par) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> ver(V);
        for(int i=0;i<edges.size();i++){
            ver[edges[i][0]].push_back(edges[i][1]);
            ver[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){ //for disconnected trees
            if(!visited[i]){
                if(cyc(ver, visited, -1, i))
                    return true;
            }
        }
        return false;
    }
};

//Using BFS
class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V,false);

        for(int i=0;i<V;i++){

            if(visited[i]) continue;

            queue<pair<int,int>> q;
            q.push({i,-1});
            visited[i]=true;

            while(!q.empty()){

                auto [node,parent]=q.front();
                q.pop();

                for(int nei:adj[node]){

                    if(!visited[nei]){
                        visited[nei]=true;
                        q.push({nei,node});
                    }
                    else if(nei!=parent){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
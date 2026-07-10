// Directed Graph Cycle
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& pathVisited) {

        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbour : adj[node]) {

            if (!visited[neighbour]) {
                if (dfs(neighbour, adj, visited, pathVisited))
                    return true;
            }
            else if (pathVisited[neighbour]) {
                return true;
            }
        }

        pathVisited[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited))
                    return true;
            }
        }

        return false;
    }
};
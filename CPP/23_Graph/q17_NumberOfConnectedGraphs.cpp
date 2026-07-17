//Find the number of connected components in an undirected graph using DFS

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;

    for (int nei : adj[node]) {
        if (!vis[nei])
            dfs(nei, adj, vis);
    }
}

int connectedComponents(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis);
            count++;
        }
    }

    return count;
}
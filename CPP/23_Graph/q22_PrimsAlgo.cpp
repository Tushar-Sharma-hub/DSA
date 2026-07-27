//Minimum Spanning Tree using Prim's Algorithm
//MST is a subset of edges of a connected, edge-weighted undirected graph that connects all the vertices together, 
//without any cycles and with the minimum possible total edge weight.
//If there are V vertices in the graph, then the MST will have exactly V-1 edges.
//Greedy Algo

//Approach:
// 1. Create a priority queue to store the edges of the graph.
// 2. Create a vector to store the visited vertices.
// 3. Push the first vertex into the priority queue with weight 0.
// 4. While the priority queue is not empty, do the following:
//    a. Pop the top edge from the priority queue.
//    b. If the vertex is already visited, continue to the next iteration.
//    c. Mark the vertex as visited and add the weight of the edge to the sum
//    d. For each adjacent vertex of the current vertex, if it is not visited, push the edge into the priority queue.
// 5. Return the sum of the weights of the edges
class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        vector<bool> vis(V, false);
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            sum += wt;
            for (auto [v, w] : adj[u]) {
                if (!vis[v]) {
                    pq.push({w, v});
                }
            }
        }
        return sum;
    }
};
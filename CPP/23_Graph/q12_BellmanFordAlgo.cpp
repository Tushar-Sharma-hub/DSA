/*
================== Bellman-Ford ==================

-> Single Source Shortest Path (SSSP)

-> Works for:
   ✔ Positive weights
   ✔ Negative weights

-> Also detects Negative Weight Cycles.

-> Uses Edge List representation:
   {u, v, wt} (As bellman doen't need to visit the neighbours of a node, it just relaxes all edges V-1 times)

-> Idea:
   Relax every edge (V-1) times.

-> Relaxation:
   if(dist[u] + wt < dist[v])
       dist[v] = dist[u] + wt;

-> Why V-1?
   Longest shortest path can have at most V-1 edges.

-> Negative Cycle:
   After V-1 iterations,
   if any edge can still relax,
   then a negative weight cycle exists.

Time Complexity : O(V * E)
Space Complexity: O(V)

=================================================
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src)
{
    // Initialize all distances as infinity
    vector<int> dist(V, INT_MAX);

    // Distance to source is 0
    dist[src] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++)
    {
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // Skip if source vertex is unreachable
            if(dist[u] == INT_MAX)
                continue;

            // Relax the edge
            if(dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for Negative Weight Cycle
    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            cout << "Negative Weight Cycle Exists";
            return {};
        }
    }

    // Return shortest distances
    return dist;
}
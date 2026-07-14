//Dijkstra's Algo
//Greedy Algo
//Dijkstra's Algorithm finds the shortest distance from one source node to every other node in a weighted graph.
// Conditions
// Graph can be directed or undirected.
// All edge weights must be non-negative.
// If negative edges exist, use Bellman-Ford instead.

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int src)
{
    // Min Heap
    // Stores {distance, node}
    // The node with the smallest distance is always on top.
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // Distance array
    // Initially every node is unreachable (INF)
    vector<int> dist(V, INT_MAX);

    // Distance from source to itself is 0
    dist[src] = 0;

    // Push source node into priority queue
    pq.push({0, src});

    // Continue until all reachable nodes are processed
    while (!pq.empty())
    {
        // Get the node with the smallest current distance
        auto [distance, node] = pq.top();
        pq.pop();

        // If this is an outdated entry, skip it.
        // Example:
        // Queue has (5,2) but dist[2] is already 3.
        // Then 5 is useless.
        if (distance > dist[node])
            continue;

        // Traverse all neighbours of the current node
        for (auto it : adj[node])
        {
            int adjNode = it.first;   // Neighbour
            int weight = it.second;   // Edge weight

            // Relaxation Step
            // Check if going through 'node'
            // gives a shorter path to adjNode
            if (distance + weight < dist[adjNode])
            {
                // Update shortest distance
                dist[adjNode] = distance + weight;

                // Push updated distance into the min heap
                // (Duplicates are allowed. Older ones are ignored later.)
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // Return shortest distances from source
    return dist;
}
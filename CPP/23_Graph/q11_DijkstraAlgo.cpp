//Dijkstra's Algo
//Greedy Algo
//Dijkstra's Algorithm finds the shortest distance from one source node to every other node in a weighted graph.
// Conditions
// Graph can be directed or undirected.
// All edge weights must be non-negative.
// If negative edges exist, use Bellman-Ford instead.

//Approach:
// 1. Create a priority queue to store the nodes of the graph.
// 2. Create a vector to store the distance of each node from the source node.
// 3. Push the source node into the priority queue with distance 0.
// 4. While the priority queue is not empty, do the following:
//    a. Pop the top node from the priority queue.
//    b. If the distance of the popped node is greater than the distance stored in the distance vector,continue to the next iteration.
//    c. For each adjacent node of the popped node, 
//    if the distance of the popped node plus the weight of the edge is less than the distance stored in the distance vector, 
//    update the distance vector and push the adjacent node into the priority queue.
vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int src)
{
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto [distance, node] = pq.top();
        pq.pop();
        if (distance > dist[node])
            continue;
        for (auto it : adj[node])
        {
            int adjNode = it.first;   // Neighbour
            int weight = it.second;   // Edge weight
            if (distance + weight < dist[adjNode])
            {
                dist[adjNode] = distance + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
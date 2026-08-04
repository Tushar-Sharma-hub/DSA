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

//In dijikstra approach we will just run the dijikstra algo from every city and count the number of cities reachable 
//within the threshold distance and return the city with minimum count. If there are multiple such cities, 
//return the city with the greatest number.
class Solution {
public:

    int dijkstra(int src,
                 vector<vector<pair<int,int>>>& adj,
                 int n,
                 int threshold) {

        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){

            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto [neighbor, weight] : adj[node]){

                if(dist[node] + weight < dist[neighbor]){

                    dist[neighbor] = dist[node] + weight;

                    pq.push({
                        dist[neighbor],
                        neighbor
                    });
                }
            }
        }

        // Count cities within threshold
        int count = 0;

        for(int i = 0; i < n; i++){
            if(i != src && dist[i] <= threshold)
                count++;
        }

        return count;
    }


    int findTheCity(int n,
                    vector<vector<int>>& edges,
                    int distanceThreshold) {

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int minCount = INT_MAX;
        int ans = -1;

        // Dijkstra from every city
        for(int src = 0; src < n; src++){

            int count = dijkstra(
                src,
                adj,
                n,
                distanceThreshold
            );

            if(count <= minCount){
                minCount = count;
                ans = src;
            }
        }

        return ans;
    }
};
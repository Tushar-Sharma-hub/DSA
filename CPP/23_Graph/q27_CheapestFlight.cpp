// 787. Cheapest Flights Within K Stops
// There are n cities connected by some number of flights. You are given an array flights 
// where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
// If there is no such route, return -1.

//Intuition:
// Like bellman ford algo, we can use BFS to find the shortest path from src to dst with at most k stops.

// So in this we firstly create dist array to store the minimum cost to reach each node from src. Then we use a queue to perform BFS.
// In the queue we store the current node, the cost to reach that node and the number of stops taken to reach that node.
// We maintain stops to ensure that we do not exceed k stops. If we reach the destination node, we update the minimum cost to reach that node.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n];
        for(auto &it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u].push_back({v, wt});
        }
        queue<pair<int, pair<int,int>>> q;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push({src, {0, -1}});
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int u = val.first;
            int cost = val.second.first;
            int stops = val.second.second;
            if(stops == k) continue;
            for(auto [v, wt] : graph[u]){
                if(cost + wt < dist[v]){
                    dist[v] = cost + wt;
                    q.push({v, {cost + wt, stops + 1}});
                }
            }
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
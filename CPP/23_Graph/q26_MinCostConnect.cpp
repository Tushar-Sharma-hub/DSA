// 1584. Min Cost to Connect All Points
// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
// |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
// Return the minimum cost to make all points connected. All points are connected if there is exactly 
// one simple path between any two points.

class Solution {
public:
    int dist(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int d = dist(points[i], points[j]);
                adj[i].push_back({d, j});
                adj[j].push_back({d, i});
            }
        }
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        vector<bool> vis(n, false);
        pq.push({0,0});
        int ans = 0;
        while(!pq.empty()) {
            auto [wt,node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            ans += wt;
            for(auto [w,v] : adj[node]) {
                if(!vis[v]) {
                    pq.push({w,v});
                }
            }
        }
        return ans;
    }
};
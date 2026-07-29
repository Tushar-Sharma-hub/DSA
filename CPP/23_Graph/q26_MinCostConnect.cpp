// 1584. Min Cost to Connect All Points
// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
// |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
// Return the minimum cost to make all points connected. All points are connected if there is exactly 
// one simple path between any two points.

class Solution {
public:
    int manDist(vector<vector<int>>& points, int p1, int p2) {
        return abs(points[p1][0] - points[p2][0])+abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        vector<bool> mstSet(n, false);
        int mstCost = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;
            if (mstSet[node]) continue;
            mstSet[node] = true;
            mstCost += wt;
            for (int next = 0; next < n; next++) {
                if (!mstSet[next]) {
                    int dist = manDist(points, node, next);
                    pq.push({dist, next});
                }
            }
        }
        return mstCost;
    }
};
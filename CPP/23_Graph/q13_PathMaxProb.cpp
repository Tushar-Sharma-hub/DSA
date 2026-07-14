// 1514. Path with Maximum Probability
// You are given an undirected weighted graph of n nodes (0-indexed), 
// represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b 
// with a probability of success of traversing that edge succProb[i].
// Given two nodes start and end, find the path with the maximum probability of success to go 
// from start to end and return its success probability.
// If there is no path from start to end, return 0. Your answer will be accepted if it 
// differs from the correct answer by at most 1e-5.

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> prob(n, 0.0);
        prob[start] = 1.0;
        pq.push({1.0, start});
        while(!pq.empty())
        {
            auto [currProb, node] = pq.top();
            pq.pop();
            if(currProb < prob[node])
                continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                double edgeProb = it.second;
                if(currProb * edgeProb > prob[adjNode]){
                    prob[adjNode] = currProb * edgeProb;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }
        return prob[end];
    }
};
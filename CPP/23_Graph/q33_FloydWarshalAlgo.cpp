//Floyd Warshall Algorithm
//It is used to find the shortest distance between all pairs of vertices in a given edge weighted directed graph.
//Multisource shortest path algorithm.
//T.C= O(V^3) S.C=O(V^2)

//Just calculate the distance between all pairs of vertices using the formula:
//dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) for all vertices k in the graph. 
//If there is no edge between two vertices, we can represent the distance as infinity (or a large value) in the distance matrix. 
//After running the algorithm, the distance matrix will contain the shortest distances between all pairs of vertices. 
//If there is no path between two vertices, the distance will remain as infinity.
class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(dist[i][k]!=1e8 && dist[k][j]!=1e8){
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }
    }
};
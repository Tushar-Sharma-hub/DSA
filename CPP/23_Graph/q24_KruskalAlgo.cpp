//Kruskal Algo
//It is used to find the Minimum Spanning Tree of a graph.
//In this we will sort the edges in increasing order of their weights and keep adding the edges to the MST 
//if they don't form a cycle with the already included edges.
//We can use Disjoint Set Union (DSU) to check if the edge forms a cycle or not.
//If the two vertices of the edge belong to the same set, then adding this edge will form a cycle 
//and we will not include this edge in the MST.
//If the two vertices of the edge belong to different sets, then adding this edge will not form a cycle 
//and we will include this edge in the MST and merge the two sets.
//Time Complexity: O(ElogE + E*4*α) where E is the number of edges and 
//α is the inverse Ackermann function which is very slow growing and can be considered as a constant(O(1)) for all practical purposes. 
//So the time complexity can be considered as O(ElogE).
//Space Complexity: O(V) where V is the number of vertices in the graph.
// T.C of find() is O(α(V)) ≈ O(1)
// T.C of union() is O(α(V)) ≈ O(1)
// T.C of Cycle check (find(u) == find(v))	O(α(V)) ≈ O(1)
// T.C of Sort edges O(E log E)
// T.C of Kruskal's Algorithm O(E log E)

class Solution {
public:
    vector<int> parent, size;
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {
        parent.resize(V);
        size.resize(V, 1);
        for (int i = 0; i < V; i++)
            parent[i] = i;
        sort(edges.begin(), edges.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[2] < b[2];
             });
        int mstWeight = 0;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (find(u) != find(v)) { //just check if the two vertices belong to different sets or not, 
                //if they belong to the same set then adding this edge will form a cycle and we will not include this edge in the MST.
                mstWeight += wt;
                unionBySize(u, v);
            }
        }
        return mstWeight;
    }
};
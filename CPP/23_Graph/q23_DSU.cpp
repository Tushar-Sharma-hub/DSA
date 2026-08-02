// Disjoint Set Union (DSU) / Union-Find
// Optimizations:
// 1. Path Compression
// 2. Union by Rank
// 3. Union by Size

class DisjointSetUnion {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) { //initialize the parent of each node to itself
            parent[i] = i;
        }
    }
    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }
    //Rank is the depth of the tree, we will attach the smaller tree to the root of the larger tree.
    //Depth will increase only when both trees have the same depth, so we will increase the rank of the root of the larger tree by 1.
    void unionByRank(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    //Size is the number of nodes in the tree, we will attach the smaller tree to the root of the larger tree.
    void unionBySize(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
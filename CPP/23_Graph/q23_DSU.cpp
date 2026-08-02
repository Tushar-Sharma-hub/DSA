// Disjoint Set Union (DSU) / Union-Find
// Optimizations:
// 1. Path Compression
// 2. Union by Rank
// 3. Union by Size

#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the ultimate parent (representative) of a node
    // Path compression makes future find operations faster
    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    // ---------------------------------------------------
    // UNION BY RANK
    // Attach the tree with smaller rank under the tree
    // with larger rank.
    // If ranks are equal, attach either one and increase
    // the rank of the new root.
    // ---------------------------------------------------
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

    // ---------------------------------------------------
    // UNION BY SIZE
    // Attach the smaller set under the larger set.
    // size[root] stores the number of nodes in that set.
    // ---------------------------------------------------
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

    void getInfo() {

        cout << "Parent Array:\n";
        for (int i = 0; i < parent.size(); i++)
            cout << parent[i] << " ";

        cout << "\n\nRank Array:\n";
        for (int i = 0; i < rank.size(); i++)
            cout << rank[i] << " ";

        cout << "\n\nSize Array:\n";
        for (int i = 0; i < size.size(); i++)
            cout << size[i] << " ";

        cout << endl;
    }
};

int main() {

    DisjointSetUnion dsu(6);

    // Using Union by Rank
    dsu.unionByRank(0, 2);
    dsu.unionByRank(1, 3);
    dsu.unionByRank(2, 5);
    dsu.unionByRank(0, 3);

    cout << "Ultimate parent of 2: "
         << dsu.find(2) << endl;

    dsu.getInfo();


    cout << "\n-------------------------\n";

    // Separate DSU to demonstrate Union by Size
    DisjointSetUnion dsu2(6);

    dsu2.unionBySize(0, 2);
    dsu2.unionBySize(1, 3);
    dsu2.unionBySize(2, 5);
    dsu2.unionBySize(0, 3);
    dsu2.unionBySize(0, 4);

    cout << "Ultimate parent of 2: "
         << dsu2.find(2) << endl;

    dsu2.getInfo();

    return 0;
}
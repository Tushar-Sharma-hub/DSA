//Disjoint Set Union (DSU) or Union-Find data structure implementation in C++.
#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion {
    vector<int> parent;
    vector<int> rank;
    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    void getInfo() {
        cout << "Parent Array:\n";
        for (int i = 0; i < parent.size(); i++)
            cout << parent[i] << " ";
        cout << "\n\n";

        cout << "Rank Array:\n";
        for (int i = 0; i < rank.size(); i++)
            cout << rank[i] << " ";
        cout << endl;
    }
};

int main() {

    DisjointSetUnion dsu(6);

    dsu.unionByRank(0, 2);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(1, 3);
    dsu.unionByRank(2, 5);
    dsu.unionByRank(0, 3);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(0, 4);

    dsu.getInfo();

    return 0;
}
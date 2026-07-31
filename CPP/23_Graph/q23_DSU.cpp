//Disjoint Set Union (DSU) or Union-Find data structure implementation in C++.
//DSU is a data structure which helps to solve problems related to connected components in a graph, groups of elements, and equivalence relations.
#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion {
    public:
    vector<int> parent;
    vector<int> rank;
    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    //Find fxn is used to find the representative of the set that a particular element belongs to.
    //In this implementation if the element is not the representative of its set, we recursively call find on its parent until we reach the representative.
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]); //path compression optimization
    }
    //Union fxn is used to merge two sets into one.
    //In this implementation, we first find the representatives of the two sets that the elements belong to.
    //If the representatives are different, we merge the sets by making one representative the parent of the other.
    //We also use the rank array to keep track of the depth of the trees representing the sets,
    //and we always attach the smaller tree to the root of the larger tree to keep the overall depth of the trees as small as possible.
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
// 947. Most Stones Removed with Same Row or Column
// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, 
// return the largest possible number of stones that can be removed.

class DisjointSetUnion {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSetUnion(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        DisjointSetUnion ds(n);

        unordered_map<int, int> row;
        unordered_map<int, int> col;

        for (int i = 0; i < n; i++) {
            int r = stones[i][0];
            int c = stones[i][1];

            if (row.count(r))
                ds.unionBySize(i, row[r]);
            else
                row[r] = i;

            if (col.count(c))
                ds.unionBySize(i, col[c]);
            else
                col[c] = i;
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.find(i) == i)
                components++;
        }

        return n - components;
    }
};
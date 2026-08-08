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

//Approach:
//1.We use dsu to connect the stones in the same row and column.
//2.For stone row it will be 0,1,2,3,... and for stone column it will be maxRow+1,maxRow+2,...
//3.We will count the number of connected components and return n - cnt.
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSetUnion ds(maxRow + maxCol + 2);
        unordered_map<int, int> stoneNodes; //stoneNodes will store the unique nodes that are part of the connected components
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; 
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.find(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;
    }
};
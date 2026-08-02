// 1319. Number of Operations to Make Network Connected
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a 
// network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
// Any computer can reach any other computer directly or indirectly through the network.
// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, 
// and place them between any pair of disconnected computers to make them directly connected.
// Return the minimum number of times you need to do this in order to make all the computers connected. 
// If it is not possible, return -1.

class DisjointSetUnion {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSetUnion(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
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
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        DisjointSetUnion ds(n);
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            ds.unionBySize(a,b);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        return cnt-1;
    }
};
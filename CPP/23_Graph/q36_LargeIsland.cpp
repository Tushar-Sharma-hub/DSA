// 827. Making A Large Island
// Hard
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation.
// An island is a 4-directionally connected group of 1s.

//Intuition:
//1. We will use Disjoint Set Union (DSU) to find the size of each island in the grid.
//2. We will use cell number to represent each cell in the grid. Cell number = row * n + colm.
//3. We will iterate through the grid and for each cell with value 1, we will check its 4 neighbors and 
//if the neighbor is also 1, we will union the two cells in the DSU.
//4. After that we will iterate through the grid again and for each cell with value 0, we will check its 4 neighbors and
//if the neighbor is 1, we will find the parent of the neighbor in the DSU and add the size of the island to the current cell. 
//We will keep track of the maximum size of the island we can get by changing a 0 to 1.
//5. Finally we will return the maximum size of the island we can get by changing a 0 to 1.
class dsu {
public:
    vector<int> parent;
    vector<int> size;
    dsu(int n) {
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
private:
    bool isValid(int row,int colm,int n){
        return row>=0 && row<n && colm>=0 && colm<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        dsu ds(n*n);
        for(int row=0;row<n;row++){
            for(int colm=0;colm<n;colm++){
                if(grid[row][colm]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=colm+dc[i];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        int nodeNo=row * n +colm;
                        int adjNodeNo=newr * n +newc;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int colm=0;colm<n;colm++){
                if(grid[row][colm]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int> comp;
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=colm+dc[i];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        comp.insert(ds.find(newr*n+newc));
                    }
                }
                int st=0;
                for(auto it:comp){
                    st+=ds.size[it];
                }
                mx=max(mx,st+1);
            }
        }
        for(int cellNo=0;cellNo<n*n;cellNo++){
            mx=max(mx,ds.size[ds.find(cellNo)]);
        }
        return mx;
    }
};
// 934. Shortest Bridge
// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
// You may change 0's to 1's to connect the two islands to form one island.
// Return the smallest number of 0's you must flip to connect the two islands.


// Approach: Using dfs to mark first island and push all its coordinates into a queue. 
// Then we will use multi-source bfs to find the shortest path to the second island. 
// We will keep track of the level of bfs and return the level when we reach the second island.
class Solution {
public:
    queue<pair<int,int>> q;
    void dfs(int i,int j, vector<vector<int>> & grid){
        int n=grid.size();
        grid[i][j]=2;
        q.push({i,j});
        if(i+1<n && grid[i+1][j]==1)
            dfs(i+1,j,grid);
        if(i-1>=0 && grid[i-1][j]==1)
            dfs(i-1,j,grid);
        if(j+1<n && grid[i][j+1]==1)
            dfs(i,j+1,grid);
        if(j-1>=0 && grid[i][j-1]==1)
            dfs(i,j-1,grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        bool check=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    check=true;
                    break;
                }
            }
            if(check) break;
        }
        int lvl=0;
        int dirs[]={0,1,0,-1,0};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int idx=x+dirs[i];
                    int idy=y+dirs[i+1];
                    if(idx>=0 && idx<n && idy>=0 && idy<n){
                        if(grid[idx][idy]==1) return lvl;
                        if(grid[idx][idy]==0){
                            grid[idx][idy]=2;
                            q.push({idx,idy});
                        }
                    }
                }
            }
            lvl++;
        }
        return lvl;
    }
};
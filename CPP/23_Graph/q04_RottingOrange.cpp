// 994. Rotting Oranges
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){ 
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int ans=0;
        while(q.size()!=0){
            auto m=q.front();
            int i = m.first.first;
            int j = m.first.second;
            int t = m.second;
            ans=max(ans,t);
            q.pop();
            if(i-1>=0 && vis[i-1][j]==false && grid[i-1][j]==1){
                q.push({{i-1,j},t+1});
                vis[i-1][j]=true;
            }
            if(i+1<grid.size() && vis[i+1][j]==false && grid[i+1][j]==1){
                q.push({{i+1,j},t+1});
                vis[i+1][j]=true;
            }
            if(j-1>=0 && vis[i][j-1]==false && grid[i][j-1]==1){
                q.push({{i,j-1},t+1});
                vis[i][j-1]=true;
            }
            if(j+1<grid[0].size() && vis[i][j+1]==false && grid[i][j+1]==1){
                q.push({{i,j+1},t+1});
                vis[i][j+1]=true;
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return ans;
    }
};
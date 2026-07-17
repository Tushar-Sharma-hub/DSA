// 1034. Coloring A Border
// You are given an m x n integer matrix grid, and three integers row, col, and color. 
// Each value in the grid represents the color of the grid square at that location.
// Two squares are called adjacent if they are next to each other in any of the 4 directions.
// Two squares belong to the same connected component if they have the same color and they are adjacent.
// The border of a connected component is all the squares in the connected component that are 
// either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).
// You should color the border of the connected component that contains the square grid[row][col] with color.
// Return the final grid.

// In this , we will use BFS to traverse the connected component and find the border cells. 
// We will keep track of visited cells to avoid processing them multiple times.
// For each cell, we will check its neighbors to determine if it is a border cell.
// If it is, we will add it to a list of border cells. 
// Finally, we will change the color of all border cells to the specified color and return the modified grid.
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int pc = grid[row][col];
        queue<pair<int,int>> q;
        q.push({row,col});
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        vis[row][col] = true;
        vector<pair<int,int>> border;
        while(q.size()!=0){
            auto m = q.front();
            q.pop();
            int i = m.first;
            int j = m.second;
            bool isBorder = false;
            if(i-1<0 || grid[i-1][j]!=pc) isBorder = true;
            else if(!vis[i-1][j]){
                q.push({i-1,j});
                vis[i-1][j]=true;
            }
            if(i+1>=grid.size() || grid[i+1][j]!=pc) isBorder = true;
            else if(!vis[i+1][j]){
                q.push({i+1,j});
                vis[i+1][j]=true;
            }
            if(j-1<0 || grid[i][j-1]!=pc) isBorder = true;
            else if(!vis[i][j-1]){
                q.push({i,j-1});
                vis[i][j-1]=true;
            }
            if(j+1>=grid[0].size() || grid[i][j+1]!=pc) isBorder = true;
            else if(!vis[i][j+1]){
                q.push({i,j+1});
                vis[i][j+1]=true;
            }
            if(isBorder)
                border.push_back({i,j});
        }
        for(auto x : border){
            grid[x.first][x.second] = color;
        }
        return grid;
    }
};
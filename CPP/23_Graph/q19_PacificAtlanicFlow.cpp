// 417. Pacific Atlantic Water Flow
// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
// The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
// The island is partitioned into a grid of square cells. 
// You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west 
// if the neighboring cell's height is less than or equal to the current cell's height. 
// Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) 
// to both the Pacific and Atlantic oceans.


//Approach:
// We will take two BFS traversals, one for Pacific and one for Atlantic.
// We will take the whole row and column for both oceans and push them into the queue.
// Then we will traverse the queue and check for the adjacent cells, if they are not visited and their height is greater than or equal to the current cell's height, we will push them into the queue and mark them as visited.
// Finally, we will check for the cells which are visited by both BFS traversals and push them into the answer vector.
class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int row;
    int colm;
    vector<vector<int>> h;
    vector<vector<bool>> bfs(queue<pair<int,int>> & q){
        vector<vector<bool>> vis(row,vector<bool>(colm,false));
        while(q.size()>0){
            auto cell=q.front();q.pop();
            int i=cell.first;
            int j=cell.second;
            vis[i][j]=true;
            for(int d=0;d<4;d++){
                int nr=i+dir[d][0];
                int nc=j+dir[d][1];
                if(nr<0 || nc<0 || nr>=row || nc>=colm) continue;
                if(vis[nr][nc]) continue;
                if(h[nr][nc]<h[i][j]) continue;
                q.push({nr,nc});
            }
        }
        return vis;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row=heights.size();
        colm=heights[0].size();
        h=heights;
        queue<pair<int,int>> pbfs;
        queue<pair<int,int>> abfs;
        for(int i=0;i<row;i++){
            pbfs.push({i,0});
            abfs.push({i,colm-1});
        }
        for(int i=1;i<colm;i++){
            pbfs.push({0,i});
        }
        for(int i=0;i<colm-1;i++){
            abfs.push({row-1,i});
        }
        vector<vector<bool>> p=bfs(pbfs);
        vector<vector<bool>> a=bfs(abfs);
        vector<vector<int>> ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<colm;j++){
                if(p[i][j] && a[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
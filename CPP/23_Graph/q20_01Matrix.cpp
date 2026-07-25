// 542. 01 Matrix
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two cells sharing a common edge is 1.

//Approach: 
// We will use BFS to solve this problem. We will push all the cells with 0 into the queue and mark them as visited. 
// Then we will traverse the queue and check for the adjacent cells, if they are not visited and their value is 1, 
// we will update their distance and push them into the queue. Finally, we will return the answer matrix.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,1e9));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j]=0;
                }
            }
        }
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && mat[nrow][ncol]==1){
                    if(dist+1<ans[nrow][ncol]){
                        ans[nrow][ncol]=dist+1;
                        q.push({{nrow,ncol},dist+1});
                    }
                }
            }
        }
        return ans;
    }
};
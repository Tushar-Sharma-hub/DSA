// Rotting Apples
// Given an N x M matrix where each cell can have one of three values:
// • Ø representing an empty cell,
// • 1 representing a fresh apple, or
// • 2 representing a rotten apple.
// Every minute, any fresh apple that is 4 -directionally adjacent to a rotten apple becomes rotten.
// 4 -directionally adjacent cells of a cell (i, j) are cell (i - 1, j), (i + 1, j), (i, j - 1) and (i, j + 1).
// Find the minimum number of minutes that must elapse until no cell has a fresh apple. If this is impossible, return -1.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int row, colm;
	cin>>row>>colm;
	vector<vector<int>> v(row,vector<int>(colm));
	queue<pair<int,int>> q;
	int fresh=0;
	for(int i=0;i<row;i++){
	    for(int j=0;j<colm;j++){
	        cin>>v[i][j];
	        if(v[i][j]==2) q.push({i,j});
	        if(v[i][j]==1) fresh++;
	    }
	}
	int min=0;
	while(q.size()!=0 && fresh>0){
	    int n=q.size();
	    while(n!=0){
	        auto p=q.front();
	        int a=p.first;
	        int b=p.second;
	        if(a-1>=0){
	            if(v[a-1][b]==1){
	                fresh--;
    	            v[a-1][b]=2;
    	            q.push({a-1,b});
	            }
	        }
	        if(a+1<row){
	            if(v[a+1][b]==1){ fresh--;
	            v[a+1][b]=2;
	            q.push({a+1,b});}
	        }
	        if(b-1>=0){
	            if(v[a][b-1]==1){ fresh--;
	            v[a][b-1]=2;
	            q.push({a,b-1});}
	        }
	        if(b+1<colm){
	            if(v[a][b+1]==1){ fresh--;
	            v[a][b+1]=2;
	            q.push({a,b+1});}
	        }
	        q.pop();
	        n--;
	    }
	    min++;
	}
	if(fresh>0) cout<<-1;
	else cout<<min;
}

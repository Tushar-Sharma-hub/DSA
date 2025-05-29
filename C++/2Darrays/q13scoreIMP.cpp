//LC-861
//A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
// Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
// Return the highest possible score after making any number of moves (including zero moves).
#include<iostream>
using namespace std;

int matrixScore(vector<vector<int>>& grid) {
    int row=grid.size();
    int colm=grid[0].size();
    //First flip all 0 in 1st column by fliping there rows.
    for(int i=0;i<row;i++){
        if(grid[i][0]==0){
            for(int j=0;j<colm;j++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
    }
    //Now flip the columns which have number of zeroes greater than number of one's.
    for(int j=0;j<colm;j++){
        int noo=0;
        int noz=0;
        for(int i=0;i<row;i++){
            if(grid[i][j]==0) noz++;
            else noo++;
        }
        if(noz>noo){
            for(int i=0;i<row;i++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
    }
    //Now just calc the dec value(by converting binary to dec) of each row and add to get the highest sum which can be obtained by given matrix.
    int sum=0;
    for(int i=0;i<row;i++){
        int base=1;
        for(int j=colm-1;j>=0;j--){
            sum += grid[i][j]*base;
            base*=2;
        }
    }
    return sum;
}
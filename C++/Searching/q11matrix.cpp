//The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.
#include<iostream>
using namespace std;

int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{21,22,25,26}};
    int x;
    cout<<"Enter element to search:";
    cin>>x;
    //This method takes O(row+log(colm)) not O(log(row*colm)) time complexity cause it iterates through all rows.
    // bool ans=false;
    // int row=matrix.size();
    // int colm=matrix[0].size();
    // int low=0,high=colm-1;
    // int i=0;
    // while(low<=high && i<row){
    //     if(x>=matrix[i][0] && x<=matrix[i][colm-1]){
    //         int mid=low+(high-low)/2;
    //         if(matrix[i][mid]==x){
    //             ans=true;
    //             break;
    //         }
    //         else if(matrix[i][mid]<x) low=mid+1;
    //         else high=mid-1; 
    //     }
    //     else i++;
    // }
    // cout<<ans;

    //O(log(row*colm))
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midElement = matrix[mid / n][mid % n]; // Mapping 1D index to 2D

            if (midElement == x) {
                return true;
            }
            else if (midElement < x) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false;
    return 0;
}
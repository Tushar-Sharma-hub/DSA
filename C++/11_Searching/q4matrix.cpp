// Given a matrix having 0-1 only where each row is sorted in increasing order, find the row with the
// maximum number of 1’s.
// Input matrix : 0 1 1 1
// 0 0 1 1
// 1 1 1 1 // this row has maximum 1s
// 0 0 0 0
// Output: 2
#include<iostream>
using namespace std;

int firstoccOf1(vector<int> & v){
    int n=v.size();
    int low=0,high=n-1,result=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]==1){
            result=mid;
            high=mid-1;
        }
        else if(v[mid]==0) low=mid+1;
    }
    return result;
}

int main(){
    vector<vector<int>> matrix={{0,0,0,1},{0,0,1,1},{1,1,1,1},{0,1,1,1}};
    int maxRowIndex = -1;
    int maxCount = 0;
    for (int i = 0; i < matrix.size(); i++) {
        int firstIndex = firstoccOf1(matrix[i]);
        if (firstIndex != -1) {
            int count = matrix[i].size() - firstIndex;
            if (count > maxCount) {
                maxCount = count;
                maxRowIndex = i;
            }
        }
    }
    cout << "Row with maximum 1s is: " << maxRowIndex << endl;
    return 0;
}
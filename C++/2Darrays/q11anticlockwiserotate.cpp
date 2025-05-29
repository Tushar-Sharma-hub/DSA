//Write a program to rotate the matrix by 90 degrees anti-clockwise.
//Tranpose and then reverse the columns value.
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter rows and columns:";
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter the elements of the matrix:";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    //Transpose.
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    //Reverse columns.
    for(int j = 0; j < m; j++){
        int top = 0, bottom = n - 1;
        while(top < bottom){
            swap(arr[top][j], arr[bottom][j]);
            top++;
            bottom--;
        }
    }
    cout<<"Anti-clockwise rotate:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
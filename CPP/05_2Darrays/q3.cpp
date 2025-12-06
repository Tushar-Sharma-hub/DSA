//Add two matrices.
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter rows and columns for the matrxi:";
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter elements of first matrix:";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int arr2[n][m];
    cout<<"Enter elements of second matrix:";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr2[i][j];
        }
    }
    int add[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            add[i][j]=arr[i][j]+arr2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<add[i][j]<<" ";
        }
        cout<<endl;
    }
}
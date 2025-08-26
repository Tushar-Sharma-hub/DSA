//Write a program to print the transpose of the matrix entered by the user and store it in a new matrix.-Leetcode-867.
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter rows and columns:";
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int transp[m][n];
    cout<<endl<<"Transpose:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            transp[i][j]=arr[j][i];
            cout<<transp[i][j]<<" ";
        }
        cout<<endl;
    }
}
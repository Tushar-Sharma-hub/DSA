//Print the multiplication of two matrix.
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter rows and columns of 1st matrix:";
    cin>>n>>m;
    int arr1[n][m];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr1[i][j];
        }
    }
    int a,b;
    cout<<"Enter rows and columns of second matrix:";
    cin>>a>>b;
    if(m!=a){
        cout<<"The column of 1st matrix and row of 2nd matrix should e equal for multiplication.";
        return 1;
    }
    int arr2[a][b];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr2[i][j];
        }
    }
    int res[n][b];
    for(int i=0;i<n;i++){
        for(int j=0;j<b;j++){
            res[i][j]=0;
            for(int k=0;k<m;k++){
                res[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<b;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
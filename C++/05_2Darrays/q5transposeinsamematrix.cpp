//Write a program to print the transpose of the matrix entered by the user and store it in a same matrix.
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
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            //swap
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }

    cout<<endl<<"Transpose:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
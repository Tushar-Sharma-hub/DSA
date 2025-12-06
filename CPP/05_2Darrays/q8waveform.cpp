//Print the matrix in wave form.
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
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int j=m-1;j>=0;j--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
    return 0;
}
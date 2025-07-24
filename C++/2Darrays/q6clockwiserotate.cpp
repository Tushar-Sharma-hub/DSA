//Rotate the matrix by 90 degree.--LC48
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
    // Step 1: Transpose the matrix.
    cout<<"After transpose:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }

    // Step 2: Reverse each row.
    for(int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while(left < right) {
            swap(arr[i][left], arr[i][right]);
            left++;
            right--;
        }
    }

    //print
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
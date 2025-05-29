//Write a C++ program to find the largest element of a given 2D array of integers.
#include<iostream>
using namespace std;
int main(){
    int arr[4][2];
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    int max=arr[0][0];
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            if(arr[i][j]>max) max=arr[i][j];
        }
    }
    cout<<"The maximum in the 2D array is: "<<max;
}
//Write a program to store roll number and marks obtained by 4 students side by side in a matrix.
#include<iostream>
using namespace std;
int main(){
    int marks[4][2];
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cin>>marks[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cout<<marks[i][j]<<" ";
        }
        cout<<endl;
    }
}
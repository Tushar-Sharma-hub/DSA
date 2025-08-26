// Given an array of marks of students, if the markof any student is less than 35 print its roll number.
//  [roll number here refers to the index of the array.]
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of students:";
    cin>>n;
    int marks[n];
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" student marks:";
        cin>>marks[i];
    }
    for(int i=0;i<n;i++){
        if(marks[i]<35){
            cout<<"Student with less than 35 marks roll no is :"<<i<<endl;
        }
    }
}
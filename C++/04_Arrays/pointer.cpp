//how to use pointer with array.
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,31,3};

    //There are two ways to assign a pointer to whole array:
    //int* ptr=arr;    
    //int* ptr=&arr[0];

    int* ptr=arr;
    for(int i=0;i<5;i++){
        cout<<*ptr<<" ";
        ptr++;  //this will not inc just only 1 it will inc 4 as it is integer data type.Check the output
    }
    return 0;
}
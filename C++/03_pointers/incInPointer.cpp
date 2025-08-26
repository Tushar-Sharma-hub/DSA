#include<iostream>
using namespace std;
int main(){
    int arr[]={4,2,3,42,4};
    int* ptr=arr;
    for(int i=0;i<5;i++){
        cout<<ptr<<endl;
        ptr++;  //this will not inc just only 1 it will inc 4 as it is integer data type.Check the output
    }
}
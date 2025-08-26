//Calculate hcf using recursive call.
#include<iostream>
using namespace std;

//Simple way to find hcf.
// int hcf(int a,int b){
//     for(int i=min(a,b);i>=2;i--){
//         if(a%i==0 && b%i==0) return i;
//     }
//     return -1;
// }

// Recusive call:
// Euclidean Algorithm (Efficient and Shorter
// Time complexity is O(log(a+b)).
int hcf(int a, int b) {
    if (b == 0) return a;
    return hcf(b, a % b);
}


int main(){
    int a=24;
    int b=60;
    cout<<hcf(a,b);
    return 0;
}
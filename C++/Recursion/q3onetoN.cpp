//Print 1 to N.Using recursion
#include<iostream>
using namespace std;

//using two parameters.
// void print(int i,int n){
//     if(i>n) return;
//     cout<<i<<endl;
//     print(i+1,n);
// }

//Using single paramter.
//For reversing things we make recursive call before printing.
void print(int n){
    if(n==0) return ;
    print(n-1); //the loop will go on unitl n becomes 0 and then backtracking printing n which will give output from 1 to n.
    cout<<n<<endl;
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    print(n);
    return 0;
}
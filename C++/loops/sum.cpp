#include<iostream>
using namespace std;
int main(){
    int n,sum=0;          //Sum 1 to n.
    cout<<"Enter n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout << "The sum from 1 to " << n << " is: " << sum << endl;
}
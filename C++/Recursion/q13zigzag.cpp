// Print zig-zag
// Output
// 111 (input-1)
// 211121112 (input-2)
// 321112111232111211123 (input-3)
// 432111211123211121112343211121112321112111234 (input-4)
#include<iostream>
using namespace std;

void zigzag(int n){
    if(n==0) return;
    cout<<n;
    zigzag(n-1);
    cout<<endl<<n;
    zigzag(n-1);
    cout<<endl<<n;
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    zigzag(n);
    return 0;
}
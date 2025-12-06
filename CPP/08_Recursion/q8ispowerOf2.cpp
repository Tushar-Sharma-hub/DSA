//Return true if power of 2.
#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
if(n == 1) {
return true;
}
if(n % 2 == 0) {
return isPowerOfTwo(n / 2);
}
return false;
}

int main(){
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n);
    return 0;
}
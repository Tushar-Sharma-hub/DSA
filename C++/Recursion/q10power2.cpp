//Power of a number with less time complexity (logarithm method).
#include<iostream>
using namespace std;

int power(int a,int n){ //T.C=O(logn) S.C=O(logn)
    if(n==0) return 1;
    if(n==1) return a;
    if(n%2==0){
        int ans=power(a,n/2);
        return ans*ans;
    }
    else{
        int ans=power(a,n/2);
        return ans*ans*a;
    }
}

int main(){
    cout<<power(3,6);
    return 0;
}
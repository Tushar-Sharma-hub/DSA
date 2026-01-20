#include<iostream>
using namespace std;

int main(){
    long long a,b,n;
    cin>>a>>b>>n;
    long long temp=a;
    while(n!=0){
        for(int i=1;i<=9;i++){
            if(a%10==i) continue;
            a*=10;
            a+=i;
            if(a%b==0){
                break;
            }
            a/=10;
        }
        n--;
    }
    if(temp==a) cout<<-1;
    else cout<<a;
}
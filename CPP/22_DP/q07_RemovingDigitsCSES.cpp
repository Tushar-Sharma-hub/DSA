// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
// Input The only input line has an integer n.
// Output Print one integer: the minimum number of steps.
// Example
// Input:
// 27
// Output:
// 5
// Constraints-> 1<=n<=10^6
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> dp(28,-1);

vector<int> get_digits(int n){
    vector<int> v;
    while(n>0){
        if(n%10!=0) v.push_back(n%10);
        n/=10;
    }
    return v;
}

int f(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    vector<int> d = get_digits(n);
    int result=INT_MAX;
    for(int i=0;i<d.size();i++){
        result=min(result,f(n-d[i]));
    }
    return dp[n] = 1+result;
}

//Tabulation(bottom-up)
int fbu(int n){
    dp[0]=0;
    for(int i=1;i<=9;i++) dp[i]=1;
    for(int i=10;i<=n;i++){
        vector<int> d=get_digits(i);
        int result=INT_MAX;
        for(int j=0;j<d.size();j++){
            result=min(result,dp[i-d[j]]);
        }
        dp[i]=1+result;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fbu(n)<<endl;
    for(int i=0;i<dp.size();i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}
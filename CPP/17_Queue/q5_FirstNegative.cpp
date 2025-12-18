// First Negative in each window of size K
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

vector<int> negativeK(vector<int> arr,int k){
    queue<int> q;
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i]<0) q.push(i);
    }
    int j;
    for(int i=0;i<=n-k;i++){
        j=i+k-1;
        while(!q.empty() && q.front() < i){
            q.pop();
        }
        if(q.size()!=0 && q.front()<=j){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){
    vector<int> arr={0,-1,-2,3,4,-5,6,4,7,-8};
    vector<int> ans;
    ans=negativeK(arr,3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
// maximum sum subarray of size k.
#include<iostream>
using namespace std;

int maxsubarray(vector<int> v,int k){
    int n=v.size();
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=v[i];
    }
    int i=1,j=k,maxsum=sum,maxidx=0;
    while(j<n){
        sum=sum+v[j]-v[i-1];
        if(sum>maxsum) {
            maxsum=sum;
        }
        i++;j++;
    }
    return maxsum;
}

int main(){
    vector<int> v={7,1,2,5,8,4,9,3,6};
    int k=3;
    cout<<maxsubarray(v,k);
    return 0;
}
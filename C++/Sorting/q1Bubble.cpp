//Push zeroes to end while maintaining the relative order of other elements.(Use of Bubble sort as we have to maintain the relative order)
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={5,4,0,0,3,0,4,0,8,0};
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]==0){
                swap(v[j],v[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
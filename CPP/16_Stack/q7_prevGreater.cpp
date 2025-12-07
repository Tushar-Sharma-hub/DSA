//Previous greater element , if not found then -1.
#include<iostream>
#include<stack>
using namespace std;

vector<int> prevGreater(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n);
    stack<int> temp;
    ans[0]=-1;
    temp.push(arr[0]);
    for(int i=1;i<n;i++){
        while(temp.size()!=0 && temp.top()<arr[i]) temp.pop();
        if(temp.size()==0) ans[i]=-1;
        else ans[i]=temp.top();
        temp.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr={3,1,2,5,4,6,2,3};
    arr=prevGreater(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}
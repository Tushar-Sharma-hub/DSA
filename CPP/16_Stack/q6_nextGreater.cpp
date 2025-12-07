//Next greater element , if not found then -1.
#include<iostream>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n);
    stack<int> temp;
    ans[n-1]=-1;
    temp.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(temp.size()!=0 && temp.top()<arr[i]) temp.pop();
        if(temp.size()==0) ans[i]=-1;
        else ans[i]=temp.top();
        temp.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr={3,1,2,5,4,6,2,3};
    arr=nextGreater(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}
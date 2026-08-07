//Next greater element , if not found then -1.
#include<iostream>
#include<stack>
using namespace std;

//Approach:
//1. Create a stack to store the elements of the array.
//2. Traverse the array from right to left.
//3. For each element, pop elements from the stack until the top of the stack is
//   greater than the current element or the stack is empty.
//4. If the stack is empty, then there is no greater element for the current element
//   and we store -1 in the answer array. Otherwise, we store the top of the stack in the answer array.
//5. Push the current element onto the stack.
vector<int> nextGreater(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n);
    stack<int> temp;
    ans[n-1]=-1;
    temp.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(temp.size()!=0 && temp.top()<=arr[i]) temp.pop();
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
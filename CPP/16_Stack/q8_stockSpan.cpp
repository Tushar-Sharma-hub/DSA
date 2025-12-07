//Stock Span - For each day, the stock span is the number of consecutive previous days 
//(including today) where the price was less than or equal to today’s price.
#include<iostream>
#include<stack>
using namespace std;

vector<int> stock(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n);
    stack<int> temp;
    ans[0]=1;
    temp.push(0);
    for(int i=1;i<n;i++){
        while(temp.size()!=0 && arr[temp.top()]<arr[i]) temp.pop();
        if(temp.size()==0) ans[i]=-1;
        else ans[i]=temp.top();
        ans[i]=i-ans[i];
        temp.push(i);
    }
    return ans;
}

int main(){
    vector<int> arr={100,80,60,81,70,60,75,85};
    arr=stock(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}
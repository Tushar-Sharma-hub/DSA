//Remove elements at even idx.(consider 0-indexing).
#include<iostream>
#include<queue>
using namespace std;

void display(queue<int> q){
    int n=q.size();
    cout<<"Current queue: ";
    for(int i=0;i<n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
void removeEven(queue<int>& q){
    int n=q.size();
    for(int i=0;i<n;i++){
        if(i%2!=0){
            int x=q.front();
            q.push(x);
        }
        q.pop();
    }
}

int main(){
    queue<int> q;
    int n;
    cout<<"Enter the size of queue: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cout<<"Enter "<<i+1<<" element: ";
        cin>>x;
        q.push(x);
    }
    display(q);
    removeEven(q);
    cout<<"After removing even idx elements: "<<endl;
    display(q);
    return 0;
}
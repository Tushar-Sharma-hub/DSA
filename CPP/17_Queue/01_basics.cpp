#include <iostream>
#include <queue>
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

void reverse(queue<int>& q){ //Using a stack.
    cout<<"Before reversing queue: "<<endl;
    display(q);
    stack<int> st;
    while(q.size()>0){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
}

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    q.pop();

    cout << "After pop, Front: " << q.front() << endl;

    cout << "Size: " << q.size() << endl;

    if (q.empty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";
    display(q);
    cout<<endl;
    reverse(q);
    cout<<"After reversing queue: "<<endl;
    display(q);
}
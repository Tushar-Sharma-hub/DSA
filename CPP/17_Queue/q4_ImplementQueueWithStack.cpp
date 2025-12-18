//LC-232
class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st1.size()==0) return -1;
        while(st1.size()!=0){
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st2.top();
        st2.pop();
        while(st2.size()!=0){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    int peek() {
        if(st1.size()==0) return -1;
        while(st1.size()!=0){
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st2.top();
        while(st2.size()!=0){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(st1.size()==0) return true;
        return false;
    }
};
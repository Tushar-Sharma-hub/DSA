//get min in stack in O(1) t.c and O(1) s.c .
class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        min=LLONG_MAX;
    }
    
    void push(int val) {
        long long x=(long long) val;
        if(st.size()==0){
            st.push(x);
            min=x;
        }
        else if(x>=min) st.push(x);
        else{
            st.push(2*x-min); //making dummy push which is less than val so that we can genrate oldmin later.
            min=x;
        }
    }
    
    void pop() {
        if(st.top()<min){ //idhr apni dummy value pkd lenge , as out top element is coming less than min.
            long long oldmin=2*min-st.top();
            min=oldmin;
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<min) return (int)min;
        return (int)st.top();
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//Here the drawback that we get in array implementation will get finished using circular logic in the array.
class MyCircularQueue {
public:
    int f,b,s,c;//front,back,curr size,capacity
    vector<int> arr;
    MyCircularQueue(int k) {
        f=0;b=0;s=0;c=k;
        vector<int> v(k);
        arr=v;
    }
    
    bool enQueue(int value) {
        if(s==c) return false;
        arr[b]=value;
        b++;
        if(b==c) b=0; //if back gets at last then make back =0.
        s++;
        return true;
    }
    
    bool deQueue() {
        if(s==0) return false;
        f++;
        if(f==c) f=0; //if front gets at last make it f=0.
        s--; 
        return true;
    }
    
    int Front() {
        if(s==0) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(s==0) return -1;
        if(b==0) return arr[c-1]; //as when we push back is one step ahead so we have to print arr[b-1] but if b==0 then arr[c-1] is ans.
        return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0) return true;
        return false;
    }
    
    bool isFull() {
        if(s==c) return true;
        return false;
    }
};
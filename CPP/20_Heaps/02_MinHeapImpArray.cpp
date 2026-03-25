#include<iostream>
using namespace std;

class minHeap{
public:
    int *arr;
    int idx;
    int capacity;
    minHeap(int size){
        capacity = size;
        arr = new int[capacity + 1];
        idx = 1;
    }
    int top(){
        return arr[1];
    }
    void push(int val){
        if(idx > capacity){
            cout << "Heap Overflow\n";
            return;
        }
        arr[idx]=val;
        int i=idx;
        idx++;
        while(i>1){
            int p=i/2;
            if(arr[p]>arr[i]){
                swap(arr[p],arr[i]);
            }
            else break;
            i=p;
        }
    }

    void pop(){
        swap(arr[idx-1],arr[1]);
        idx--;
        int i=1;
        int l=2;
        int r=3;
        while(l<idx){
            if(r>=idx){
                if(arr[l]<arr[i]){ swap(arr[l],arr[i]); i=l;}
                else break;
            }
            else{
                int minIdx;
                if(arr[l]>arr[r]) minIdx=r;
                else minIdx=l;

                if(arr[minIdx]<arr[i]){ swap(arr[minIdx],arr[i]); i=minIdx;}
                else break;
            }
            l=2*i;
            r=2*i+1;
        }
    }
    ~minHeap(){
        delete[] arr;
    }
};
int main(){
    minHeap q(10);

    q.push(10);
    q.push(2);
    q.push(14);
    q.push(11);
    q.push(1);
    q.push(4);

    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
}
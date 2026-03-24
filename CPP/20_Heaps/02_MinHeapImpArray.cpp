#include<iostream>
using namespace std;

class minHeap{
public:
    int *arr;
    int idx;
    int capacity;

    minHeap(int size){
        capacity = size;
        arr = new int[capacity + 1]; // 1-based indexing
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

    // Heapify function
    void heapify(int i){
        while(true){
            int l = 2*i;
            int r = 2*i + 1;
            int smallest = i;

            if(l < idx && arr[l] < arr[smallest]) smallest = l;
            if(r < idx && arr[r] < arr[smallest]) smallest = r;

            if(smallest != i){
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else break;
        }
    }

    void pop(){
        if(idx == 1) return;

        swap(arr[1], arr[idx-1]);
        idx--;

        heapify(1);
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

    cout<<q.top()<<endl; // 1
    q.pop();
    cout<<q.top()<<endl; // 2

    return 0;
}
// It is a type of Stable Sort.
// Working - Bubble sort compares each pair of adjacent elements in the array.
// If the current element is greater than the next one, they are swapped.
// This way, the largest element "bubbles up" to the end in each pass.
// The process repeats for the remaining elements.
// We use a boolean flag 'swaping' to check if any swap happened in the current pass.
// If no swap happens, it means the array is already sorted, so we stop early.
#include<iostream>
#include<vector>
using namespace std;

void bubblesort(vector<int>& arr){ //Time Complexity-Best case-O(n) Avg Case-O(n^2) Worst Case-O(n^2)
    int n=arr.size();
    for(int i=0;i<n;i++){
        bool swaping=true; //We use this bool to break the 
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaping=true;
            }
        }
        if(swaping==false) return ;
    }
}

int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements:";
    for(int i=0 ; i<n;i++){
        cin>>arr[i];
    }
    // sort(arr.begin(),arr.end());//This built in fxn takes O(nlogn) time complex.
    bubblesort(arr);
    cout<<"After sorting:";
    for(int i=0 ; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
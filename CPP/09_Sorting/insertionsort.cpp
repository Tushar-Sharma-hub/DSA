//Stable sort.
#include <iostream>
#include <vector>
using namespace std;

//T.C-Best case-O(n) Avg Case-O(n^2) Worst Case-O(n^2)
void insertionsort(vector<int>& arr) {
    int n = arr.size();
    for(int i=1;i<n;i++){
        int j=i;
        while(j>=1 && arr[j]<arr[j-1]){ //We compare the current element with the previous one and if it is smaller, we swap them. We continue this process until we find the correct position for the current element or we reach the beginning of the array.
            swap(arr[j],arr[j-1]);
            j--; 
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionsort(arr);

    cout << "After insertion sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

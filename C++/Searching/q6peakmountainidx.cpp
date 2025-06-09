// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.
//LC-852
#include<iostream>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1, high = arr.size() - 2; 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid; 
            } else if (arr[mid] > arr[mid - 1]) {
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
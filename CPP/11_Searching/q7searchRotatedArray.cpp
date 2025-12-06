// Leetcode 33: Search in Rotated Sorted Array
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();

    // Step 1: Find the index of the smallest element (pivot)
    int low = 0, high = n - 1, pivotidx = 0;

    // Modified binary search to find the pivot point (smallest element)
    while (low < high) {
        int mid = low + (high - low) / 2;

        // If mid element is greater than the high element, pivot must be in the right half
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            // Else, the pivot is in the left half (including mid)
            high = mid;
        }
    }

    // After the loop, low == high and points to the pivot index
    pivotidx = low;

    // Step 2: Decide in which part to perform binary search
    low = 0, high = n - 1;

    // If the target is in the sorted right half
    if (target >= nums[pivotidx] && target <= nums[n - 1]) {
        low = pivotidx; // Search in the right half
    } else {
        high = pivotidx - 1; // Search in the left half
    }

    // Step 3: Standard binary search in the decided half
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid; // Target found
        else if (nums[mid] > target) high = mid - 1; // Search left
        else low = mid + 1; // Search right
    }

    // Target not found
    return -1;
}

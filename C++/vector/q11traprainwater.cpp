//Traping rain water Leet Code-42.
#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0; // Not enough bars to trap water

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], height[i]);
    }

    rightMax[n-1] = height[n-1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], height[i]);
    }

    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(leftMax[i], rightMax[i]) - height[i];
    }

    return water;
}
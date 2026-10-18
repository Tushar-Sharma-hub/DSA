// 75. Sort Colors
// You are given an array nums with n objects colored red, white, or blue, 
// sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

class Solution {
public:
    void sortColors(vector<int>& v) {
        int n=v.size();
        int low=0,mid=0,high=n-1;
        while (mid <= high) {
            if(v[mid]==0){
                swap(v[low],v[mid]);
                low++;
                mid++;
            }else if(v[mid]==1){
                mid++;
            }else{
                swap(v[high],v[mid]);
                high--;
            }
        }
    }
};
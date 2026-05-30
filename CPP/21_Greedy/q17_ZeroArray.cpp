// 2357. Make Array Zero by Subtracting Equal Amounts
// You are given a non-negative integer array nums. In one operation, you must:
// Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
// Subtract x from every positive element in nums.
// Return the minimum number of operations to make every element in nums equal to 0.

//Just count the number of unique non-zero elements in the array. 
//Each unique non-zero element will require one operation to reduce it to zero, and all occurrences of that element will be reduced in the same operation.
// Therefore, the minimum number of operations needed is equal to the count of unique non-zero elements in the array.
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        vector<int>temp(101,0);
        for(int num : nums) {
            temp[num]++;
        }
        for(int i=1; i<temp.size(); i++) {
            if(temp[i]>0) {
                count++;
            }
        }
        return count;
    }
};
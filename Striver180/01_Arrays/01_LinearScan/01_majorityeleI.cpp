// 169. Majority __type_pack_element_alias
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

class Solution {
public:
    //Logic: This works because the majority element appears more than n/2 times, so it will always be the last remaining element after pairing different elements.
    int majorityElement(vector<int>& nums) {
        int count=0;
        int choose=0;
        for(int e:nums){
            if(count==0){
                choose=e;
            }
            if(choose==e){
                count++;
            }else{
                count--;
            }
        }
        return choose;
    }
};
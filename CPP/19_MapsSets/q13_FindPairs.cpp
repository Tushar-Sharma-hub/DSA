// 1865. Finding Pairs With a Certain Sum
class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int> m2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int x: nums2){
            m2[x]++;
        }
    }
    
    void add(int index,int val) {
        m2[nums2[index]]--; //remove old value from the map
        nums2[index] += val;
        m2[nums2[index]]++; //add new value to the map
    }
    
    int count(int tot) {
        int ans = 0;
        for(int x: nums1){
            int need = tot - x;
            if(m2.count(need)){ //count is used to check if the key exists in the map, it returns 1 if it exists and 0 if it doesn't
                ans += m2[need]; //if the key exists, we can make pairs with all the values that are equal to the key, so we add the count of that key to the answer
            }
        }
        return ans;
    }
};
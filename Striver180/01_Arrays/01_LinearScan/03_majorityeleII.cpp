// 229. Majority Element II
// Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.

class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        int cnt1 = 0, cnt2 = 0; //as we want n/3, we can have at most 2 elements that can be the answer, so we maintain 2 counters and 2 elements.
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != v[i]) {
                cnt1 = 1;
                el1 = v[i];
            }
            else if (cnt2 == 0 && el1 != v[i]) {
                cnt2 = 1;
                el2 = v[i];
            }
            else if (v[i] == el1) cnt1++;
            else if (v[i] == el2) cnt2++;
            else {
                cnt1--, cnt2--;
            }
        }

        vector<int> ls;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el1) cnt1++;
            if (v[i] == el2) cnt2++;
        }
        if (cnt1 > int(n / 3)) ls.push_back(el1);
        if (cnt2 > int(n / 3)) ls.push_back(el2);
        return ls;
    }
};
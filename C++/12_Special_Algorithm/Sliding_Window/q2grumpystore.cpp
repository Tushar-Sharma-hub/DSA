// 1052. Grumpy Bookstore Owner

// There is a bookstore owner that has a store open for n minutes. 
// You are given an integer array customers of length n where customers[i] is the number of the customers that enter the store at the 
// start of the ith minute and all those customers leave after the end of that minute.

// During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner 
// is grumpy during the ith minute, and is 0 otherwise.

// When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.

// The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.

// Return the maximum number of customers that can be satisfied throughout the day.
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) sum += customers[i];
        }
        int a = 1, b = minutes;
        int firstidx = 0, secondidx = minutes - 1;
        int maxloss = sum;
        while (b < n) {
            sum += (grumpy[b] == 1 ? customers[b] : 0);
            sum -= (grumpy[a - 1] == 1 ? customers[a - 1] : 0);
            if (sum > maxloss) {
                maxloss = sum;
                firstidx = a;
                secondidx = b;
            }
            a++;
            b++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i >= firstidx && i <= secondidx) grumpy[i] = 0;
            if (grumpy[i] == 0) ans += customers[i];
        }
        return ans;
    }
};
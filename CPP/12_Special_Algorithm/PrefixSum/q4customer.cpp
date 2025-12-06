// You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

// if the ith character is 'Y', it means that customers come at the ith hour
// whereas 'N' indicates that no customers come at the ith hour.
// If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

// For every hour when the shop is open and no customers come, the penalty increases by 1.
// For every hour when the shop is closed and customers come, the penalty increases by 1.
// Return the earliest hour at which the shop must be closed to incur a minimum penalty.

// Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.
// (LC-2483)
#include<iostream>
using namespace std;

class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size();
        vector<int> pre(n + 1, 0);
        vector<int> suf(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (cust[i] == 'N' ? 1 : 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + (cust[i] == 'Y' ? 1 : 0);
        }
        int min=INT_MAX,result=0;
        for(int i=0;i<n+1;i++){
            pre[i]=pre[i]+suf[i];
            if(pre[i]<min) {
                min=pre[i];
                result=i;
            }
        }
        return result;
    }
};
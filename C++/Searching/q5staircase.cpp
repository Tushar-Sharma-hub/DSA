// You have n coins and you want to build a staircase with these coins. The staircase consists of k
// rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
// Given the integer n, return the number of complete rows of the staircase you will build.
// Example 1:
// Input: n = 5
// Output: 2
// Explanation: Because the 3rd row is incomplete, we return 2.
// Example 2:
// Input: n = 8
// Output: 3
// Explanation: Because the 4th row is incomplete, we return 3.
#include<iostream>
using namespace std;

// Brute force.
// int main() {
//     int n;
//     cout << "Enter number of coins: ";
//     cin >> n;

//     int i = 1;
//     int rows = 0;
    
//     while (n >= i) {
//         n -= i;
//         i++;
//         rows++;
//     }

//     cout << "Complete rows: " << rows << endl;
//     return 0;
// }

int arrangeCoins(int n) {
        int low=0,high=n;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long cur=mid*(mid+1)/2; //total number of coins needed to complete till mid row.
            if(cur==n) return mid;
            else if(cur<n) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
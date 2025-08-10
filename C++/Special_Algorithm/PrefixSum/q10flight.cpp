// 1109. Corporate Flight Bookings

// There are n flights that are labeled from 1 to n.

// You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents 
// a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

// Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0] - 1; 
            int last = bookings[i][1];      
            int seats = bookings[i][2];
            answer[first] += seats;
            if (last < n) {
                answer[last] -= seats;
            }
        }
        for (int i = 1; i < n; i++) {
            answer[i] += answer[i - 1];
        }
        return answer;
    }
};
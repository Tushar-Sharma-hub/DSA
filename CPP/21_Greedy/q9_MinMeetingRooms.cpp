/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
// Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] 
// (start_i < end_i), find the minimum number of rooms required to schedule all meetings without any conflicts.
// Note: (0,8),(8,10) is NOT considered a conflict at 8.
// Example 1:
// Input: intervals = [(0,40),(5,10),(15,20)]
// Output: 2
// Explanation:
// room1: (0,40)
// room2: (5,10),(15,20)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> s;
        vector<int> e;
        for(auto temp:intervals){
            s.push_back(temp.start);
            e.push_back(temp.end);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int i=0,j=0,room=0,ans=0;
        while(i<s.size() && j<e.size()){
            if(s[i]<e[j]){
                room++;
                ans=max(ans,room);
                i++;
            }
            else if(s[i]>e[j]){
                room--;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};

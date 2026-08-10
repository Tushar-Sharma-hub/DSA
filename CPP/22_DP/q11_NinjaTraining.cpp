// Ninja's training
// A ninja has planned a n-day training schedule. Each day he has to perform one of three activities
//  - running, stealth training, or fighting practice. 
// The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, 
// based on the activity and the given day.
// Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running,
//  stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.

class Solution{
public:
    int ninjaTraining(vector<vector<int>>& matrix){
        int n=matrix.size();
        vector<int> dp=matrix[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int> cur(3);
            cur[0]=matrix[i][0]+max(dp[1],dp[2]);
            cur[1]=matrix[i][1]+max(dp[0],dp[2]);
            cur[2]=matrix[i][2]+max(dp[0],dp[1]);
            dp=cur;
        }
        return max(dp[0],max(dp[1],dp[2]));
    }
};
// Minimum Cost to cut a board into squares
// Difficulty: MediumAccuracy: 60.83%Submissions: 30K+Points: 4
// Given a board of dimensions n × m that needs to be cut into n*m squares. The cost of making a cut along a horizontal or vertical edge is provided in two arrays:

// x[]: Cutting costs along the vertical edges (length-wise).
// y[]: Cutting costs along the horizontal edges (width-wise).
// Find the minimum total cost required to cut the board into squares optimally.
class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int hs=1,vs=1;
        int n1=x.size(),n2=y.size();
        int i=n1-1,j=n2-1;
        int cost=0;
        while(i>=0 && j>=0){
            if(x[i]>=y[j]){
                vs++;
                cost+= x[i]*hs;
                i--;
            }
            else{//chota
                hs++;
                cost+= y[j]*vs;
                j--;
            }
        }
        while(i>=0){
            vs++;
            cost+= x[i]*hs;
            i--;
        }
        while(j>=0){
            hs++;
            cost+= y[j]*vs;
            j--;
        }
        return cost;
    }
};

//Fractional Knapsack
//Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, 
//determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.
class Solution {
  public:
    static bool cmp(pair<int,int> & p1,pair<int,int> & p2){
        double r1=(p1.first*1.0)/(p1.second*1.0);
        double r2=(p2.first*1.0)/(p2.second*1.0);
        return r1>r2;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        //T.C:O(NlogN) S.C:O(N)
        vector<pair<int,int>> r;
        for(int i=0;i<val.size();i++){
            r.push_back({val[i],wt[i]});
        }
        sort(r.begin(),r.end(),cmp);
        double profit=0;
        for(int i=0;i<r.size();i++){
            if(r[i].second<=capacity){
                profit+=r[i].first;
                capacity-=r[i].second;
            }
            else{
                profit+=((r[i].first*1.0)/(r[i].second*1.0))*capacity;
                break;
            }
        }
        return profit;
    }
};

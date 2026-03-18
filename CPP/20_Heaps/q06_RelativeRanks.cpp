// 506. Relative Ranks
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> q;
        for(int i=0;i<score.size();i++){
            q.push({score[i],i});
        }
        int i=0;
        vector<string> ans(score.size());
        while(i<score.size()){
            auto temp=q.top();q.pop();
            if(i==0){
                ans[temp.second]="Gold Medal";
            }
            else if(i==1){
                ans[temp.second]="Silver Medal";
            }
            else if(i==2){
                ans[temp.second]="Bronze Medal";
            }
            else{
                ans[temp.second]=to_string(i+1);
            }
            i++;
        }
        return ans;
    }
};
// 134. Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas=0,tcost=0,tank=0;
        int si=0;
        for(int i=0;i<gas.size();i++){ //ans exist krta h toh ek hi hoga. toh ek loop me hi pta chlega ki ans exist krta h ya nhi. aur ans exist krta h toh wo kaha se start hoga.
            tgas+=gas[i];
            tcost+=cost[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                si=i+1;
                tank=0;
            }
        }
        if(tgas<tcost) return -1; //isse pta chlega ki ans exist krta h ya nhi. agr total gas total cost se kam h toh ans nhi milega.
        return si;
    }
};
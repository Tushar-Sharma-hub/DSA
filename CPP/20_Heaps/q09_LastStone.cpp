// 1046. Last Stone Weight
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int ele:stones){
            pq.push(ele);
        }
        while(pq.size()){
            if(pq.size()==1) return pq.top();
            int m1=pq.top();pq.pop();
            int m2=pq.top();pq.pop();
            if(m1>m2){
                pq.push(m1-m2);
            }
        }
        return 0;
    }
};
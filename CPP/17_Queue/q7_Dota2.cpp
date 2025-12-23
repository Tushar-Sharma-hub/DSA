class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        int n=senate.size();
        while(d.size()!=0 && r.size()!=0){
            int ri=r.front();r.pop();
            int di=d.front();d.pop();
            if(ri<di){
                r.push(ri+n);
            }
            else{
                d.push(di+n);
            }
        }
        if(r.size()==0) return "Dire";
        return "Radiant";
    }
};
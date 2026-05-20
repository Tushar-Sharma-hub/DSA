// 881. Boats to Save People

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        int ans=0;
        while(j>=0 && people[j]==limit){ //agr koi person limit ke barabar hai to uske liye ek boat chahiye
            ans++;
            j--;
        }
        if(j<0) return ans;
        while(i<=j){ //ek min pe pointer i aur ek max pe pointer j
            if(people[i]+people[j]<=limit){ //agr dono ka weight limit se kam ya barabar hai to dono ek boat me ja sakte hai
                i++;
                j--;
            }
            else j--; //agr dono ka weight limit se zyada hai to sirf j wala person boat me ja sakta hai jo max weight wala hai
            ans++;
        }
        return ans;
    }
};
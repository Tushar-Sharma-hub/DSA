// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes 
// multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

// Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
// LC-1402
#include<iostream>
using namespace std;

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(),satisfaction.end());
    int n=satisfaction.size();
    if(satisfaction[n-1]<0) return 0;
    int suf[n];
    suf[n-1]=satisfaction[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=satisfaction[i]+suf[i+1];
    }
    int idx=0;
    for(int i=0;i<n;i++){
        if(suf[i]>0){
            idx=i;
            break;
        }
    }
    int ans=0,time=1;
    for(int i=idx;i<n;i++){
        ans+=time*satisfaction[i];
        time++;
    }
    return ans;
}

int main(){
    vector<int> satisfaction={-1,-8,0,5,-9};
    cout<<maxSatisfaction(satisfaction);
    return 0;
}

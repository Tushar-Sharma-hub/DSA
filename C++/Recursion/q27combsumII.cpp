//Combination Sum II
// LC-40
// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

#include<iostream>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& temp, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break; 
            temp.push_back(candidates[i]);
            backtrack(result, temp, candidates, target - candidates[i], i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); 
        backtrack(result, temp, candidates, target, 0);
        return result;
    }
};

// 113. Path SumII (every path that is equals to target sum).
class Solution {
public:
    void helper(TreeNode* root, int targetSum,int sum,vector<int> v,vector<vector<int>>& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            if(sum==targetSum){
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        helper(root->left,targetSum,sum+root->val,v,ans);
        helper(root->right,targetSum,sum+root->val,v,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root,targetSum,0,{},ans);
        return ans;
    }
};
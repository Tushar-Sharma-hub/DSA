// 112. Path Sum(return target sum any path).
class Solution {
public:
    void helper(TreeNode* root, int targetSum,int sum,bool & ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            if(sum==targetSum) ans=true;
            return;
        }
        if(ans==true) return;
        helper(root->left,targetSum,sum+root->val,ans);
        helper(root->right,targetSum,sum+root->val,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        helper(root,targetSum,0,ans);
        return ans;
    }
};
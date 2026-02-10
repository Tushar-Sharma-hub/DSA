class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void helper(TreeNode* root,bool & ans){
        if(root==NULL) return ;
        int bal=abs(levels(root->left)-levels(root->right));
        if(bal>1) ans=false;
        helper(root->left,ans);
        helper(root->right,ans);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        helper(root,ans);
        return ans;
    }
};
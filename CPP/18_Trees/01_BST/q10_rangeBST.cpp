// 938. Range Sum of BST
class Solution {
public:
    int ans = 0;
    void helper(TreeNode* root, int l, int r) {
        if(!root) return;
        helper(root->left, l, r);
        if(l <= root->val && root->val <= r) ans += root->val;
        helper(root->right, l, r);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root, low, high);
        return ans;
    }
};
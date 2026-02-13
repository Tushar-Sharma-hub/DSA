// 1038. Binary Search Tree to Greater Sum Tree

class Solution {
public:
    int sum=0;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->right);
        sum+=root->val;
        root->val=sum;
        inorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;
    }
};
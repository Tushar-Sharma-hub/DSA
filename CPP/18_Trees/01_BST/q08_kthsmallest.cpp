// 230
// Kth Smallest Element in a BST
class Solution {
public:
    void inorder(TreeNode* root,int k,vector<int>& v){
        if(root==NULL) return;
        inorder(root->left,k,v);
        v.push_back(root->val);
        inorder(root->right,k,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,k,v);
        return v[k-1];
    }
};
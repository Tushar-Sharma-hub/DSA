// 1382. Balance a Binary Search Tree
class Solution {
public:
    void inorder(TreeNode* root,vector<TreeNode*>& v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    TreeNode* balance(vector<TreeNode*> v,int low,int high){
        if(low>high) return NULL;
        int mid=low+(high-low)/2;
        v[mid]->left=balance(v,low,mid-1);
        v[mid]->right=balance(v,mid+1,high);
        return v[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root,v);
        return balance(v,0,v.size()-1);
    }
};
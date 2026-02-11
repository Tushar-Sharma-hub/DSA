// 98. Validate Binary Search Tree

//Method 1: Using min and max of left and right subtree(brute force approach)
// class Solution {
// public:
//     long long minTree(TreeNode* root){
//         if(root==NULL) return LLONG_MAX;
//         return min((long long)root->val,min(minTree(root->left),minTree(root->right)));
//     }
//     long long maxTree(TreeNode* root){
//         if(root==NULL) return LLONG_MIN;
//         return max((long long)root->val,max(maxTree(root->left),maxTree(root->right)));
//     }
//     bool isValidBST(TreeNode* root) {
//         if(root==NULL) return true;
//         if(maxTree(root->left)>=(long long)root->val || minTree(root->right)<=(long long)root->val) return false;
//         return isValidBST(root->left) && isValidBST(root->right);
//     }
// };

//Method 2: Using inorder traversal(optimized approach),inorder traversal of BST is always sorted in increasing order
class Solution {
public:
    void inorder(TreeNode* root,TreeNode* &prev,bool& flag){
        if(root==NULL) return;
        inorder(root->left,prev,flag);
        if(prev!=NULL){
            if(root->val<=prev->val){
                flag=false;
                return;
            }
        }
        prev=root;
        inorder(root->right,prev,flag);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        bool flag= true;
        inorder(root,prev,flag);
        return flag;
    }
};
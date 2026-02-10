// 103. Binary Tree Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
// (i.e., from left to right, then right to left for the next level and alternate between).
class Solution {
public:
    void displayLvlval(TreeNode* root,int lvl,int n,vector<int>& v){
        if(root==NULL) return;
        if(lvl==n){ 
            v.push_back(root->val);
            return;
        }
        if(n%2==0){
            displayLvlval(root->right,lvl+1,n,v);
            displayLvlval(root->left,lvl+1,n,v);
        }
        else{
            displayLvlval(root->left,lvl+1,n,v);
            displayLvlval(root->right,lvl+1,n,v);
        }
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        int lvl=levels(root);
        for(int i=1;i<=lvl;i++){
            vector<int> v;
            displayLvlval(root,1,i,v);
            ans.push_back(v);
        }
        return ans;
    }
};
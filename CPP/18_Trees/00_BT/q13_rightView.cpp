// 199. Binary Tree Right Side View

//1 method(just push the last node val in every lvl to ans).
// class Solution {
// public:
//     void lvlorder(TreeNode* root,int lvl,int n,vector<int>& v){
//         if(root==NULL) return;
//         if(lvl==n){
//             v.push_back(root->val);
//             return;
//         }
//         lvlorder(root->left,lvl+1,n,v);
//         lvlorder(root->right,lvl+1,n,v);
//     }
//     int levels(TreeNode* root){
//         if(root==NULL) return 0;
//         return 1+max(levels(root->left),levels(root->right));
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         int lvl=levels(root);
//         for(int i=1;i<=lvl;i++){
//             vector<int> v;
//             lvlorder(root,1,i,v);
//             ans.push_back(v[v.size()-1]);
//         }
//         return ans;
//     }
// };

//2 method(just iterate through all nodes with preorder and it will update the righmost element cuz in preorder it visit rightmost elements at last.)
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void preorder(TreeNode* root,int lvl,vector<int> & ans){
        if(root==NULL) return;
        ans[lvl]=root->val;
        preorder(root->left,lvl+1,ans);
        preorder(root->right,lvl+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preorder(root,0,ans);
        return ans;
    }
};
// 257. Binary Tree Paths
class Solution {
public:
    void helper(TreeNode* root,vector<string>& ans,string s){
        if(root==NULL) return;
        string a=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            s+=a;
            ans.push_back(s);
            return;
        }
        helper(root->left,ans,s+a+"->");
        helper(root->right,ans,s+a+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,ans,"");
        return ans;
    }
};
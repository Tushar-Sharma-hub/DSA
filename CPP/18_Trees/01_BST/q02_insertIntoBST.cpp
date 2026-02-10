//701
class Solution {
public:
    void insert(TreeNode* root, int val){
        if(val>root->val){
            if(root->right==NULL){
                TreeNode* n=new TreeNode(val);
                root->right=n;
            }
            else insertIntoBST(root->right,val);
        }
        else if(val<root->val){
            if(root->left==NULL){
                TreeNode* n=new TreeNode(val);
                root->left=n;
            }
            else insertIntoBST(root->left,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* ans=new TreeNode(val);
            return ans;
        }
        insert(root,val);
        return root;
    }
};
// 1008. Construct Binary Search Tree from Preorder Traversal
class Solution {
public:
    void insert(TreeNode* root, int val){
        if(val>root->val){
            if(root->right==NULL){
                TreeNode* n=new TreeNode(val);
                root->right=n;
            }
            else insert(root->right,val);
        }
        else if(val<root->val){
            if(root->left==NULL){
                TreeNode* n=new TreeNode(val);
                root->left=n;
            }
            else insert(root->left,val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }
        return root;
    }
};
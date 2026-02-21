// 450. Delete Node in a BST
class Solution {
public:
    TreeNode* inorderPred(TreeNode* root){
        TreeNode* pred=root->left;
        while(pred->right!=NULL){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            //1.If leaf node
            if(root->left==NULL && root->right==NULL) return NULL;
            //2.If one child.
            if(root->left==NULL || root->right==NULL){
                if(root->left==NULL) return root->right;
                else return root->left;
            }
            //3.Have 2 child nodes
            if(root->left!=NULL && root->right!=NULL){
                //replace the root with inorder pred/succ
                TreeNode* pred=inorderPred(root);
                root->val=pred->val;
                root->left=deleteNode(root->left,pred->val);
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else root->right=deleteNode(root->right,key);
        return root;
    }
};
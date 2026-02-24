// Morris Traversal is a clever algorithm used to traverse a binary tree without using any extra space for a stack or recursion. 
// While standard traversals have a space complexity of 
// O(h) (where h is the height of the tree), Morris Traversal achieves O(1) space complexity.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){ //Find pred.
                TreeNode* pred=curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred=pred->right;
                }
                if(pred->right==NULL){ //link
                    pred->right=curr;
                    curr=curr->left;
                }
                else { //pred->right==curr Unlink
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
    }
};
//Using morris to solve it in O(1) s.c
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* curr = root;
        while(curr!=NULL) {
            if (curr->left!=NULL) {
                // save the right
                TreeNode* r = curr->right; curr->right = curr->left;
                // finding pred
                TreeNode* pred = curr->left;
                while(pred->right!=NULL) pred = pred->right;
                // link
                pred->right = r; 
                curr = curr->left;
            }
            else curr = curr->right;
        }
        TreeNode* temp = root;
        while(temp->right!=NULL){
            temp->left = NULL;
            temp = temp->right;
        }
    }
};
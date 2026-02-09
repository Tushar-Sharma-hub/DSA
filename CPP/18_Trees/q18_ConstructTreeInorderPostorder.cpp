class Solution {
public:
    TreeNode* build(vector<int>& inorder, int inlow, int inhigh,vector<int>& postorder, int postlow, int posthigh) {
        if (inlow > inhigh) return NULL;
        TreeNode* root = new TreeNode(postorder[posthigh]);
        if (inlow == inhigh) return root;
        int i = inlow;
        while (i <= inhigh) {
            if(inorder[i] == postorder[posthigh]) break;
            i++;
        }
        int lc=i-inlow;
        root->left=build(inorder,inlow,i-1,postorder,postlow,postlow+lc-1);
        root->right=build(inorder,i+1,inhigh,postorder,postlow+lc,posthigh-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, 0, n - 1, postorder, 0, n - 1);
    }
};
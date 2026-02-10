// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and 
// inorder is the inorder traversal of the same tree, construct and return the binary tree.
class Solution {
public:
    TreeNode* build(vector<int> preorder,int prelow,int prehigh,vector<int> inorder,int inlow,int inhigh){
        if(prelow>prehigh) return NULL;
        TreeNode* root=new TreeNode(preorder[prelow]);
        if(prelow==prehigh) return root;
        int i=inlow;
        while(i<=inhigh){
            if(inorder[i]==preorder[prelow]) break;
            i++;
        }
        int leftcount=i-inlow;
        root->left=build(preorder,prelow+1,prelow+leftcount,inorder,inlow,i-1);
        root->right=build(preorder,prelow+leftcount+1,prehigh,inorder,i+1,inhigh);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};
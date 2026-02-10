//437. Path Sum III
// Given the root of a binary tree and an integer targetSum,
// return the number of paths where the sum of the values along the path equals targetSum.
// The path does not need to start or end at the root or a leaf, 
// but it must go downwards (i.e., traveling only from parent nodes to child nodes).
class Solution {
public:
    void helper(TreeNode* root, int targetSum,long long sum,int& count){
        if(root==NULL) return;
        sum+=root->val;
        if(sum==targetSum) count++;
        helper(root->left,targetSum,sum,count);
        helper(root->right,targetSum,sum,count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0 ;
        int count=0;
        helper(root,targetSum,0,count);
        count+=pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
        return count;
    }
};
// 102. Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// 1st method
// class Solution {
// public:
//     void displayLvlval(TreeNode* root,int lvl,int n,vector<int>& v){
//         if(root==NULL) return;
//         if(lvl==n){
//             v.push_back(root->val);
//             return;
//         }
//         displayLvlval(root->left,lvl+1,n,v);
//         displayLvlval(root->right,lvl+1,n,v);
//     }
//     int levels(TreeNode* root){
//         if(root==NULL) return 0;
//         return 1+max(levels(root->left),levels(root->right));
//     }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root==NULL) return ans;
//         int lvl=levels(root);
//         for(int i=1;i<=lvl;i++){
//             vector<int> v;
//             displayLvlval(root,1,i,v);
//             ans.push_back(v);
//         }
//         return ans;
//     }
// };

//2nd method better approach
// class Solution {
// public:
//     void store(TreeNode* root,vector<vector<int>> & ans,int lvl){
//         if(root==NULL) return;
//         ans[lvl].push_back(root->val);
//         store(root->left,ans,lvl+1);
//         store(root->right,ans,lvl+1);
//     }
//     int levels(TreeNode* root){
//         if(root==NULL) return 0;
//         return 1+max(levels(root->left),levels(root->right));
//     }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root==NULL) return ans;
//         int lvl=levels(root);
//         for(int i=1;i<=lvl;i++){
//             vector<int> v;
//             ans.push_back(v);
//         }
//         store(root,ans,0);
//         return ans;
//     }
// };

//3rd method
void lvlOrderTraversalQueue(Node* root){ //BFS
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
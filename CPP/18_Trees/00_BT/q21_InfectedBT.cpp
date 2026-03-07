// 2385. Amount of Time for Binary Tree to Be Infected
class Solution {
public:
    void assign(TreeNode* root,int start,TreeNode* &first){
        if(root==NULL) return;
        if(root->val==start){
            first=root;
            return;
        }
        assign(root->left,start,first);
        assign(root->right,start,first);
    }

    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &p){
        if(root==NULL) return;

        if(root->left) p[root->left]=root;
        if(root->right) p[root->right]=root;

        markParent(root->left,p);
        markParent(root->right,p);
    }

    int amountOfTime(TreeNode* root, int start) {

        TreeNode* nh=NULL;
        assign(root,start,nh);

        unordered_map<TreeNode*,TreeNode*> parent;
        markParent(root,parent);

        unordered_set<TreeNode*> isInfected;

        queue<pair<TreeNode*,int>> q;

        q.push({nh,0});
        isInfected.insert(nh);

        int ans=0;

        while(!q.empty()){

            auto p=q.front(); q.pop();

            TreeNode* temp=p.first;
            int lvl=p.second;

            ans=lvl;

            if(temp->left && isInfected.find(temp->left)==isInfected.end()){
                q.push({temp->left,lvl+1});
                isInfected.insert(temp->left);
            }

            if(temp->right && isInfected.find(temp->right)==isInfected.end()){
                q.push({temp->right,lvl+1});
                isInfected.insert(temp->right);
            }

            if(parent.find(temp)!=parent.end() &&
               isInfected.find(parent[temp])==isInfected.end()){

                q.push({parent[temp],lvl+1});
                isInfected.insert(parent[temp]);
            }
        }

        return ans;
    }
};
// Bottom View of Binary Tree
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        unordered_map<int,int> mp;
        if(root==NULL) return {};
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int l=0;
        while(q.size()){
            auto p=q.front();q.pop();
            Node* temp=p.first;
            int val=p.second;
            l=min(l,val); // we are storing minimum value of horizontal distance in l, because we will start from l and keep on checking 
            //if there is a value for that horizontal distance in the map, if there is then we will add it to the answer and keep on incrementing l 
            //until there is no value for that horizontal distance in the map.
            mp[val]=temp->data;
            if(temp->left!=NULL){
                q.push({temp->left,val-1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,val+1});
            }
        }
        vector<int> ans;
        while(mp.find(l)!=mp.end()){
            ans.push_back(mp[l++]);
        }
        return ans;
    }
};
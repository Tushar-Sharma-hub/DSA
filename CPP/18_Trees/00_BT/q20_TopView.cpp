//We are using Map.
//Top view of a Binary Tree
class Solution {
  public:
    vector<int> topView(Node *root) {
        if(root == NULL) return {};
        map<int,int> m;
        queue<pair<Node*, int>> q; //Queue stores node and value for that node (we will store h-1 for left and h+1 fr right).
        q.push({root, 0});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            Node* t=temp.first;
            int h=temp.second;
            if(m.find(h)==m.end()){ //if h is not present in map, then only we will insert value for that h, because we want top view.
                m[h]=t->data;
            }
            if(t->left!=NULL){
                q.push({t->left,h-1}); //level order with horizontal distance. For left we will do h-1 and for right we will do h+1.
            }
            if(t->right!=NULL){
                q.push({t->right,h+1});
            }
        }
        vector<int> ans;
        for(auto p : m){
            ans.push_back(p.second);
        }
        return ans;
    }
};
//You are given the root of a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.
class Solution {
  public:
  
    bool isCBT(Node* root, int n){
        queue<Node*> q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                nullFound = true;
            } 
            else {
                if(nullFound) return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
    
    void isMax(Node* tree, bool &maxH){
        if(tree == NULL) return;
        if(tree->left){
            if(tree->data < tree->left->data){
                maxH = false;
                return;
            }
        }
        if(tree->right){
            if(tree->data < tree->right->data){
                maxH = false;
                return;
            }
        }
        
        isMax(tree->left, maxH);
        isMax(tree->right, maxH);
    }
    
    int sizeOfTree(Node* root){
        if(root==NULL) return 0;
        return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
    }
    
    bool isHeap(Node* tree) {
        int n = sizeOfTree(tree);
        bool maxH = true;
        
        isMax(tree, maxH);
        
        return isCBT(tree, n) && maxH;
    }
};
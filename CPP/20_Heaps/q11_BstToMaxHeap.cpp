//Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node.
// This condition is applied on all the nodes in the so converted Max Heap.
class Solution {
  public:
    void inorder(Node* root,vector<int> & dec){ //inorder se inc order mai store krenge arr mai.
        if(root==NULL) return;
        inorder(root->left,dec);
        dec.push_back(root->data);
        inorder(root->right,dec);
    }
    void postorder(Node* root,vector<int>& dec,int& i){
        if(root==NULL) return;
        postorder(root->left,dec,i);
        postorder(root->right,dec,i);
        root->data=dec[i++];
    }
    void convertToMaxHeapUtil(Node* root) {
        vector<int> dec;
        inorder(root,dec);
        int i=0;
        postorder(root,dec,i);
    }
};
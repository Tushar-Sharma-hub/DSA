//LC-100
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL && q!=NULL) return false;
        if(p!=NULL && q==NULL) return false;
        
        if(p->val != q->val) return false;
        bool lans=isSameTree(p->left,q->left);
        if(lans==false) return false;
        bool rans=isSameTree(p->right,q->right);
        if(rans==false) return false;
        return true;
    }
};
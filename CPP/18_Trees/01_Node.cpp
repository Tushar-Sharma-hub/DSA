#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

};

void displayTree(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

int sizeOfTree(Node* root){//no. of nodes.
    if(root==NULL) return 0;
    return 1+sizeOfTree(root->left)+sizeOfTree(root->right);
}

int sum(Node* root){
    if(root==NULL) return 0;
    int ans=root->val+sum(root->left)+sum(root->right);
    return ans;
}

int levels(Node* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}

int maxtree(Node* root){
    if(root==NULL) return INT_MIN;
    return max(root->val,max(maxtree(root->left),maxtree(root->right)));
}

int mintree(Node* root){
    if(root==NULL) return INT_MAX;
    return min(root->val,min(mintree(root->left),mintree(root->right)));
}

int prod(Node* root){ //product of all nodes.
    if(root==NULL) return 1;
    return root->val*prod(root->left)*prod(root->right);
}

int main(){
    Node* a=new Node(1); //root
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    displayTree(a);
    cout<<endl<<sizeOfTree(a);
    cout<<endl<<sum(a);
    cout<<endl<<maxtree(a);
    cout<<endl<<levels(a);
    cout<<endl<<prod(a);
    cout<<endl<<mintree(a);
}
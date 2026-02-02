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

int levels(Node* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}

void displayLvlval(Node* root,int lvl,int n){ //Print nth lvl elements.Left to right.
    if(root==NULL) return;
    if(lvl==n){ 
        cout<<root->val<<" ";
        return;
    }
    displayLvlval(root->left,lvl+1,n);
    displayLvlval(root->right,lvl+1,n);
}

void lvlTraversal(Node* root){ //DFS
    int lvl=levels(root);
    for(int i=1;i<=lvl;i++){
        displayLvlval(root,1,i);
        cout<<endl;
    }
}

Node* constructTree(int arr[],int n){
    if(n==0) return NULL;
    Node* root=new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i=1,j=2;
    while(q.size()>0 && i<n){
        Node* temp=q.front();q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
}

void leftBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return; //excluding leaf codes.
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left==NULL) leftBoundary(root->right);
}

void leafNodes(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) cout<<root->val<<" ";
    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return; //excluding leaf codes.
    rightBoundary(root->right);
    if(root->right==NULL) rightBoundary(root->left);
    cout<<root->val<<" ";
}

int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=constructTree(arr,n);
    lvlTraversal(root);
    cout<<endl;
    leftBoundary(root);
    leafNodes(root);
    rightBoundary(root->right);
    return 0;
}
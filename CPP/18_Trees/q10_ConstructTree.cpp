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

Node* constructTree(vector<int> arr){
    if(arr.size()==0) return NULL;
    Node* root=new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i=1,j=2;
    while(q.size()>0 && i<arr.size()){
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

int main(){
    vector<int> arr={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9,INT_MIN};
    Node* root=constructTree(arr);
    lvlOrderTraversalQueue(root);
}
#include<iostream>
#include<limits.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        left=NULL;
        right=NULL;
    }
};
Node* buildTree(Node* root){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    if(root==NULL){
        root=new Node(data);
    }
    if(data==-1) return NULL;
    cout<<"Enter data for insering in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for insering in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
bool bstOrNot(Node* root,int mini,int maxi){
    if(root==NULL) return true;
    if(root->data>=mini && root->data<=maxi){
        bool left=bstOrNot(root->left,mini,root->data);
        bool right=bstOrNot(root->right,root->data,maxi);
        return left && right;
    }
    return false;
}
bool validBST(Node* root){
    return bstOrNot(root,INT_MIN,INT_MAX);
}
int main(){
    Node* root=NULL;
    buildTree(root);
    cout<<validBST(root)<<endl;
    return 0;
}

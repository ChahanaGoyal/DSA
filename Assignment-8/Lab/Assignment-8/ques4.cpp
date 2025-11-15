#include<iostream>
#include<limits.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;
    root=new Node(data);
    if(data==-1) return NULL;
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
bool isBST(Node* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<=max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right;
    }
    else return false;
}
bool validateBST(Node* root){
    return isBST(root,INT_MIN,INT_MAX);
}
int main(){
    Node* root=NULL;
    cout<<"Enter data:"<<endl;
    root=buildTree(root);
    cout<<validateBST(root)<<endl;
    return 0;
}
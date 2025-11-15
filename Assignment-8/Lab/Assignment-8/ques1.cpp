#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
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
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root=NULL;
    root=buildTree(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    cout<<endl<<"Printing preorder ";
    preorder(root);
    cout<<endl<<"Printing inorder ";
    inorder(root);
    cout<<endl<<"Printing postorder ";
    postorder(root);
    return 0;
}
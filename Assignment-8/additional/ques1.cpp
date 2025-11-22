#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
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
bool isLeaf(Node* root){
    if(root==NULL) return false;
    return root->left==NULL && root->right==NULL;
}
int sumleft(Node* root){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    if(isLeaf(root->left)){
        sum+=root->left->data;
    }
    else{
        sum+=sumleft(root->left);
    }
    sum+=sumleft(root->right);
    return sum;
}
int main(){
    Node* root=NULL;
    root=buildTree(root);
    //3 9 -1 -1 20 15 -1 -1 7 -1 -1
    int sum=sumleft(root);
    cout<<"Sum is"<<sum<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<limits>
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
Node* insertBST(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertBST(root->right,d);
    }
    else{
        root->left=insertBST(root->left,d);
    }
    return root;
}
void input(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertBST(root,data);
        cin>>data;
    }
}
Node* min(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* deleteFromBST(Node* root,int d){
    if(root==NULL) return root;
    if(root->data==d){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL && root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2 children
        if(root->left!=NULL && root->right!=NULL){
            int mini=min(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
        }
        else if(root->data>d){
            root->left=deleteFromBST(root->left,d);
            return root;
        }
        else{
            root->right=deleteFromBST(root->right,d);
            return root;
        }
    }
}
int maxDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    int ldepth=maxDepth(root->left);
    int rdepth=maxDepth(root->right);
    return 1+max(ldepth,rdepth);
}
int minDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    if(root->left==NULL){
        return 1+minDepth(root->right);
    }
    if(root->right==NULL){
        return 1+minDepth(root->left);
    }
    //both children exist
    return 1+min(minDepth(root->left),minDepth(root->right));
}
int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    input(root);
    int data;
    cout<<"Enter data to be deleted"<<endl;
    cin>>data;
    root=deleteFromBST(root,data);
    cout<<"Maximum depth is "<<maxDepth(root)<<endl;
    cout<<"Minimum depth is "<<minDepth(root)<<endl;
    return 0;
}
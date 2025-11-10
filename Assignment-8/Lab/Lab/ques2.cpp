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
    while(data!=-10){
        root=insertBST(root,data);
        cin>>data;
    }
}
bool search(Node* root,int x){
    //Recursive
    // if(root==NULL){
    //     return false;
    // }
    // if(root->data==x){
    //     return true;
    // }
    // if(root->data>x){
    //     return search(root->left,x); 
    // }
    // else{
    //     return search(root->right,x);
    // }
    //Non-Recursive
    Node* temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}
Node* max(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
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
Node* inorderSuccessor(Node* root,Node* x){
    if(x->right!=NULL){
        return min(x->right);
    }
    Node* succ=NULL;
    Node* curr=root;
    while(curr!=NULL){
        if(x->data<curr->data){
            succ=curr;
            curr=curr->left;
        }
        else if(x->data>curr->data){
            curr->right;
        }
        else{
            break;
        }
    }
    return succ;
}
Node* inorderPredecessor(Node* root,Node* x){
    if(x->left!=NULL){
        return max(x->left);
    }
    Node* pred=NULL;
    Node* curr=root;
    while(curr!=NULL){
        if(x->data>curr->data){
            pred=curr;
            curr=curr->right;
        }
        else if(x->data<curr->data){
            curr=curr->left;
        }
        else{
            break;
        }
    }
    return pred;
}
int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    input(root);
    cout<<search(root,100)<<endl;
    cout<<search(root,1)<<endl;
    cout<<"Minimum is "<<min(root)->data<<endl;
    cout<<"Maximum is "<<max(root)->data<<endl;
    cout<<"Inorder successor is "<<inorderSuccessor(root,root->right)->data<<endl;
    cout<<"Inorder predecessor is "<<inorderPredecessor(root,root->left)->data<<endl;
    return 0;
}
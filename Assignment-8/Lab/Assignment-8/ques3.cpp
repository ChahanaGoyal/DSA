#include<iostream>
#include<queue>
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
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){ // traversal of previous level completed
            cout<<endl;
            if(!q.empty()){ // queue still has some child nodes left
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
            }
        }
    }
}
Node* insertIntoBST(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
         root->left=insertIntoBST(root->left,d);
    }
    return root;
}
Node* minValue(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* deleteFromBST(Node* root,int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data==val){
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
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minValue(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
        }
    }
    else if(root->data>val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
       root->right=deleteFromBST(root->right,val);
       return root; 
    }
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
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
    cout<<"Enter data to create BST:"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    root=deleteFromBST(root,90);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    cout<<"Maximum depth is "<<maxDepth(root)<<endl;
    cout<<"Minimum depth is "<<minDepth(root)<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};
void preorder(Node* root){
    if(root==NULL){
        cout<<"NULL ";
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
vector<Node*> generateTrees(int start, int end) {
    if (start > end) return {NULL};
    vector<Node*> allTrees;
    for (int i = start; i <= end; i++) {
        vector<Node*> leftTrees = generateTrees(start, i - 1);
        vector<Node*> rightTrees = generateTrees(i + 1, end);
        for (auto left : leftTrees) {
            for (auto right : rightTrees) {
                Node* root = new Node(i);
                root->left = left;
                root->right = right;
                allTrees.push_back(root);
            }
        }
    }
    return allTrees;
}
vector<Node*> Trees(int n) {
    if (n == 0) return {};
    return generateTrees(1, n);
}
int main(){
    int n;
    cout<<"Enter no. of nodes to be included in the tree"<<endl;
    cin>>n;
    vector<Node*> result=Trees(n);
    for (int i = 0; i < result.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        preorder(result[i]);
        cout << endl;
    }
    return 0;
}
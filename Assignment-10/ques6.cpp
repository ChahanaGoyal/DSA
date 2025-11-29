#include <iostream>
#define MAX 1000  // assume values are < 1000 
using namespace std;
class Node {
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
bool hashTable[MAX] = {false};
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}
bool hasDuplicateHash(Node* root) {
    if (root == NULL)
    return false;
    // If value already exists, duplicate found
    if (hashTable[root->data])
    return true;
    // Mark current node value as seen
    hashTable[root->data] = true;
    // Recur for left and right subtrees
    return hasDuplicateHash(root->left) || 
    hasDuplicateHash(root->right);
}
int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(2);  
    if (hasDuplicateHash(root))
    cout << "Duplicates Found" << endl;
    else
    cout << "No Duplicates" << endl;
    return 0;
}
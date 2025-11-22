#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};
class BSTtoDLL {
public:
    Node* prev = NULL;
    // Convert BST to sorted DLL (inorder traversal)
    void bstToDLL(Node* root, Node*& head) {
        if (!root) return;

        bstToDLL(root->left, head);
        if (!prev) {
            head = root; 
        } else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        bstToDLL(root->right, head);
    }
};
Node* mergeDLL(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;
    Node* head = NULL;
    Node* tail = NULL;
    while (h1 && h2) {
        Node* temp;
        if (h1->data < h2->data) {
            temp = h1;
            h1 = h1->right;
        } else {
            temp = h2;
            h2 = h2->right;
        }
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }
    // attach remaining nodes
    Node* remaining = h1 ? h1 : h2;
    while (remaining) {
        tail->right = remaining;
        remaining->left = tail;
        tail = remaining;
        remaining = remaining->right;
    }
    return head;
}
Node* mergeBSTs(Node* root1, Node* root2) {
    BSTtoDLL conv;
    Node* head1 = NULL;
    conv.prev = NULL;
    conv.bstToDLL(root1, head1);
    Node* head2 = NULL;
    conv.prev = NULL;
    conv.bstToDLL(root2, head2);
    return mergeDLL(head1, head2);
}
void printDLL(Node* head) {
    cout << "Sorted Doubly Linked List: ";
    while (head) {
        cout << head->data << "<->";
        head = head->right;
    }
    cout << endl;
}
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
int main() {
    Node* root1 = NULL;
    root1 = insert(root1, 30);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);
    Node* root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 25);
    root2 = insert(root2, 50);
    Node* mergedList = mergeBSTs(root1, root2);
    printDLL(mergedList);
    return 0;
}
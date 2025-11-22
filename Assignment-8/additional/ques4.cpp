#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
// Build tree from level order input
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (i < arr.size()) {
        Node* curr = q.front();
        q.pop();
        // Left child
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
// Compute right view
vector<int> rightView(Node* root) {
    vector<int> result;
    if (!root) return result;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        Node* node = NULL;
        while (size--) {
            node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        // The last node of the level is the right view element
        result.push_back(node->data);
    }
    return result;
}
int main() {
    int T;
    cout << "Enter no. of test cases" << endl;
    cin >> T;
    while (T--) {
        int n;
        cout << "Enter no. of nodes to be entered" <<endl;
        cin >> n;
        vector<int> arr(n);
        cout << "Enter value of nodes in tree level wise" << endl; 
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Node* root = buildTree(arr);
        vector<int> rv = rightView(root);
        for (int x : rv)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
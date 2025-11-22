#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(vector<int> &arr)
{
    if (arr.empty() || arr[0] == -1)
        return NULL;
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (i < arr.size())
    {
        Node *curr = q.front();
        q.pop();
        // Left child
        if (arr[i] != -1)
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        // Right child
        if (i < arr.size() && arr[i] != -1)
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int maxDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ldepth = maxDepth(root->left);
    int rdepth = maxDepth(root->right);
    return 1 + max(ldepth, rdepth);
}
int main()
{
    int T;
    cout << "Enter no. of test cases" << endl;
    cin >> T;
    while (T--)
    {
        int n;
        cout << "Enter no. of nodes to be entered" << endl;
        cin >> n;
        vector<int> arr(n);
        cout << "Enter value of nodes in tree level wise" << endl;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Node *root = buildTree(arr);
        cout << "Maximum depth is " << maxDepth(root) << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int element)
    {
        data = element;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
    int findPosition(int in[], int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    Node *solve(int in[], int post[], int &index, int inorderstart, int inorderend, int n)
    {
        // base case
        if (index < 0 || inorderstart > inorderend)
        {
            return NULL;
        }
        int element = post[index--];
        Node *root = new Node(element);
        int position = findPosition(in, element, n);
        root->right = solve(in, post, index, position + 1, inorderend, n);
        root->left  = solve(in, post, index, inorderstart, position - 1, n);
        return root;
    }
public:
    Node *buildtree(int in[], int post[], int n)
    {
        int postorderindex = n-1;
        Node *ans = solve(in, post, postorderindex, 0, n - 1, n);
        return ans;
    }
};
void printPreorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main()
{
    int n;
    cout << "Enter no.of nodes to be included in the tree" << endl;
    cin >> n;
    int in[n], post[n];
    cout << "Enter the inorder traversal" << endl;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cout << "Enter the postorder traversal" << endl;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    Solution obj;
    Node *root = obj.buildtree(in, post, n);
    cout << "The preorder traversal of the tree is " << endl;
    printPreorder(root);
    return 0;
}
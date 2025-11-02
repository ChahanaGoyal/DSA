#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node* up;
    Node* down;
    Node(int d) {
        data = d;
        right = left = up = down = NULL;
    }
};
// Function to convert 2D matrix into 4-way doubly linked list
Node* convertToDoublyLL(vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return NULL;
    int n = mat[0].size();
    // Create 2D array of node pointers
    vector<vector<Node*>> nodes(m, vector<Node*>(n, NULL));
    // Step 1: Create nodes for each matrix element
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }
    // Step 2: Link all four directions
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0)
                nodes[i][j]->left = nodes[i][j - 1];
            if (j < n - 1)
                nodes[i][j]->right = nodes[i][j + 1];
            if (i > 0)
                nodes[i][j]->up = nodes[i - 1][j];
            if (i < m - 1)
                nodes[i][j]->down = nodes[i + 1][j];
        }
    }
    // Return top-left node as head
    return nodes[0][0];
}
void printList(Node* head, int m, int n) {
    Node* row = head;
    for (int i = 0; i < m; i++) {
        Node* col = row;
        for (int j = 0; j < n; j++) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Node* head = convertToDoublyLL(mat);
    cout << "Doubly Linked List (4-directional) representation:\n";
    printList(head, mat.size(), mat[0].size());
    return 0;
}
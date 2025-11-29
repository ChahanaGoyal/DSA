#include <iostream>
#include <unordered_set>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};
Node* appendNode(Node *&head, Node *&tail, int value) {
    Node *newNode = new Node(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}
void getUnionAndIntersection(Node *head1, Node *head2,Node *&unionHead, Node *&interHead) {
    unionHead = NULL;
    interHead = NULL;
    Node *unionTail = NULL;
    Node *interTail = NULL;
    unordered_set<int> set1;
    // Insert all values from list1 into set1
    for (Node *p = head1; p != NULL; p = p->next) {
        set1.insert(p->data);
    }
    // For intersection: traverse list2, check if value in set1
    for (Node *q = head2; q != NULL; q = q->next) {
        if (set1.find(q->data) != set1.end()) {
            appendNode(interHead, interTail, q->data);
        }
    }
    // For union: union set of both lists
    // Start by inserting from list1 (we already have set1 values)
    for (int val : set1) {
        appendNode(unionHead, unionTail, val);
    }
    // Now traverse list2 and insert values not already in set1
    for (Node *q = head2; q != nullptr; q = q->next) {
        if (set1.find(q->data) == set1.end()) {
            appendNode(unionHead, unionTail, q->data);
            set1.insert(q->data);
        }
    }
}
void printList(Node *head) {
    for (Node *p = head; p != NULL; p = p->next) {
        cout << p->data;
        if (p->next) cout << " -> ";
    }
    cout << endl;
}
int main() {
    // Example: list1 = 10->15->4->20, list2 = 8->4->2->10
    Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(20);
    Node *head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(10);
    Node *unionHead = NULL, *interHead = NULL;
    getUnionAndIntersection(head1, head2, unionHead, interHead);
    cout << "Intersection list is: ";
    printList(interHead);
    cout << "Union list is: ";
    printList(unionHead);
    return 0;
}
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int d) {
        data = d;
        prev = next = NULL;
    }
};
void insertEnd(Node*& head, Node*& tail, int d) {
    Node* newNode = new Node(d);
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1)
        return head;
    Node* current = head;
    Node* newHead = NULL;
    Node* groupPrev = NULL;
    while (current) {
        int count = 0;
        Node* groupStart = current;
        // Move k nodes ahead
        Node* temp = current;
        while (count < k - 1 && temp->next) {
            temp = temp->next;
            count++;
        }
        Node* nextGroupHead = temp->next;
        // Break connection for this group
        temp->next = NULL;
        // Reverse this group
        Node* prev = NULL;
        Node* curr = groupStart;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            curr->prev = nextNode;
            prev = curr;
            curr = nextNode;
        }
        // 'prev' now points to new head of this group
        if (!newHead)
            newHead = prev;
        // Connect previous group with this one
        if (groupPrev) {
            groupPrev->next = prev;
            prev->prev = groupPrev;
        }
        // Update for next iteration
        groupPrev = groupStart;
        current = nextGroupHead;
        // Reconnect to remaining list
        if (nextGroupHead)
            nextGroupHead->prev = groupPrev;
    }
    return newHead;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    for (int i = 0; i < n; i++)
        insertEnd(head, tail, arr[i]);
    cout << "Original Doubly Linked List:\n";
    printList(head);
    head = reverseInGroups(head, k);
    cout << "\nList after reversing every group of " << k << " nodes:\n";
    printList(head);
    return 0;
}
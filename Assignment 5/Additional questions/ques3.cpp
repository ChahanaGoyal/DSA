#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;
    // detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return; // no loop
    // find start of loop
    slow = head;
    Node* prev = NULL;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    // 'slow' is now the start of loop, break it
    prev->next = NULL;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};
    head->next->next->next->next->next = head->next->next; // create loop at 3
    removeLoop(head);
    printList(head);
}
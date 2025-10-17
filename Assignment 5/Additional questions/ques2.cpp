#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* reverseK(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
        head->next = reverseK(next, k);
    return prev; // new head of this segment
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, new Node{6, NULL}}}}}};
    int k = 2;
    head = reverseK(head, k);
    printList(head);
}
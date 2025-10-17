#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0) return head;
    // find length and last node
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    temp->next = head; 
    Node* newTail = head;
    for (int i = 1; i < k; i++)
        newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node{10, new Node{20, new Node{30, new Node{40, new Node{50, NULL}}}}};
    int k = 2;
    head = rotateLeft(head, k);
    printList(head);
}
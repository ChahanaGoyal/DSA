#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node* random;
    Node(int d) {
        data = d;
        prev = next = random = nullptr;
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
    cout << "\nList (data -> random):\n";
    while (temp) {
        cout << temp->data << " -> ";
        if (temp->random)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}
void correctRandomPointer(Node* head) {
    Node* temp = head;
    while (temp) {
        Node* expected = temp->next; 
        if (temp->random != expected) {
            cout << "\nIncorrect random pointer found at node with data " << temp->data << endl;
            temp->random = expected;
            cout << "Random pointer corrected.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "\nAll random pointers are already correct.\n";
}
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    // Create sample list: 1 <-> 2 <-> 3 <-> 4
    for (int i = 1; i <= 4; ++i) {
        insertEnd(head, tail, i);
    }
    if (!head) {
        cout << "List creation failed or list is empty.\n";
        return 0;
    }
    Node* t = head;
    while (t) {
        t->random = t->next; // last node -> nullptr automatically
        t = t->next;
    }
    // Introduce one wrong random pointer safely:
    // Make sure tail is not nullptr before dereferencing
    if (tail) {
        // Example: make tail's random incorrectly point to head->next (node 2)
        if (head && head->next)
            tail->random = head->next;
    }
    cout << "Before correction:";
    printList(head);
    correctRandomPointer(head);
    cout << "\nAfter correction:";
    printList(head);
    return 0;
}
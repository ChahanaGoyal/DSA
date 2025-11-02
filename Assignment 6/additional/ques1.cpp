#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int d){
        this->data=d;
        next=NULL;
    }
};
void insertEnd(Node *&head, int d) {
    Node *newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void printCircular(Node *head) {
    if (head == NULL) return;
    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void splitCircularList(Node *head, Node *&head1, Node *&head2) {
    if (head == NULL) {
        head1 = NULL;
        head2 = NULL;
        return;
    }
    if (head->next == head) {
        head1 = head;
        head2 = NULL;
        return;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head) {
        fast = fast->next;  
    }
    head1 = head;
    head2 = slow->next;
    slow->next = head1;
    fast->next = head2;
}
int main() {
    Node *head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    cout << "Original Circular Linked List: ";
    printCircular(head);
    Node *head1 = NULL;
    Node *head2 = NULL;
    splitCircularList(head, head1, head2);
    cout << "First Half: ";
    printCircular(head1);
    cout << "Second Half: ";
    printCircular(head2);
    return 0;
}
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int getLength(Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}
Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = (len1 > len2) ? len1 - len2 : len2 - len1;
    Node *ptr1 = head1, *ptr2 = head2;
    // move longer list pointer ahead
    if (len1 > len2)
        while (diff--) ptr1 = ptr1->next;
    else
        while (diff--) ptr2 = ptr2->next;
    // move both simultaneously until they meet
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}
int main() {
    // Create two linked lists with intersection
    Node* newNode;
    Node* head1 = new Node{10, NULL};
    head1->next = new Node{20, NULL};
    newNode = new Node{30, NULL};
    head1->next->next = newNode;
    newNode->next = new Node{40, new Node{50, NULL}};
    Node* head2 = new Node{15, newNode}; // intersection at node 30
    Node* intersect = getIntersection(head1, head2);
    if (intersect) cout << "Intersection at node: " << intersect->data << endl;
    else cout << "No intersection\n";
}
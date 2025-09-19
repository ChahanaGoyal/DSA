#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
int deleteOccurrences(int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(3);
    insertAtEnd(1);
    cout << "Original List: ";
    display();
    int key = 1;
    int count = deleteOccurrences(key);
    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    display();
    return 0;
}
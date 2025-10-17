#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class DoublyCircularList {
    Node* head;
public:
    DoublyCircularList() { head = NULL; }
    void insertFront(int val) {
        Node* newNode = new Node{val, NULL, NULL};
        if (!head) {
            head = newNode;
            head->next = head->prev = head;
            return;
        }
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    void insertEnd(int val) {
        Node* newNode = new Node{val, NULL, NULL};
        if (!head) {
            head = newNode;
            head->next = head->prev = head;
            return;
        }
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    void insertAfter(int key, int val) {
        if (!head) { cout << "List empty\n"; return; }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node{val, temp->next, temp};
                temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found\n";
    }
    void insertBefore(int key, int val) {
        if (!head) { cout << "List empty\n"; return; }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node{val, temp, temp->prev};
                temp->prev->next = newNode;
                temp->prev = newNode;
                if (temp == head) head = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found\n";
    }
    void deleteFront() {
        if (!head) { cout << "List empty\n"; return; }
        if (head->next == head) { 
            delete head;
            head = NULL;
            return;
        }
        Node* last = head->prev;
        Node* temp = head;
        head = head->next;
        last->next = head;
        head->prev = last;
        delete temp;
    }
    void deleteEnd() {
        if (!head) { cout << "List empty\n"; return; }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* last = head->prev;
        Node* newLast = last->prev;
        newLast->next = head;
        head->prev = newLast;
        delete last;
    }
    void deleteSpecific(int val) {
        if (!head) { cout << "List empty\n"; return; }
        Node* temp = head;
        do {
            if (temp->data == val) {
                if (temp->next == head && temp->prev == head) { // only one node
                    delete temp;
                    head = NULL;
                    return;
                }
                if (temp == head) { 
                    deleteFront();
                    return;
                }
                if (temp == head->prev) { 
                    deleteEnd();
                    return;
                }
                // middle node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found\n";
    }
    void search(int val) {
        if (!head) { cout << "List empty\n"; return; }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Not found\n";
    }
    void display() {
        if (!head) { cout << "List empty\n"; return; }
        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main() {
    DoublyCircularList list;
    int ch, val, key;
    do {
        cout << "\n MENU \n";
        cout << "1. Insert Front\n2. Insert End\n3. Insert After Node\n4. Insert Before Node\n";
        cout << "5. Delete Front\n6. Delete End\n7. Delete Specific Node\n";
        cout << "8. Search Node\n9. Display List\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value: "; cin >> val;
                list.insertFront(val); break;
            case 2:
                cout << "Enter value: "; cin >> val;
                list.insertEnd(val); break;
            case 3:
                cout << "After which node: "; cin >> key;
                cout << "Enter value: "; cin >> val;
                list.insertAfter(key, val); break;
            case 4:
                cout << "Before which node: "; cin >> key;
                cout << "Enter value: "; cin >> val;
                list.insertBefore(key, val); break;
            case 5:
                list.deleteFront(); break;
            case 6:
                list.deleteEnd(); break;
            case 7:
                cout << "Enter value to delete: "; cin >> val;
                list.deleteSpecific(val); break;
            case 8:
                cout << "Enter value to search: "; cin >> val;
                list.search(val); break;
            case 9:
                list.display(); break;
        }
    } while (ch != 10);
    return 0;
}
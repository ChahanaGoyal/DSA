#include <iostream>
using namespace std;
//DOUBLY LINKED LIST 
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) {
        data = d;
        prev = next = NULL;
    }
};
void insertEndDLL(DNode*& head, DNode*& tail, int d) {
    DNode* newNode = new DNode(d);
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void deleteEvenDLL(DNode*& head) {
    DNode* curr = head;
    while (curr) {
        DNode* nextNode = curr->next;
        if (curr->data % 2 == 0) {
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next; // deleting head

            if (curr->next)
                curr->next->prev = curr->prev;

            delete curr;
        }
        curr = nextNode;
    }
}
void printDLL(DNode* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Doubly Linked List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
//CIRCULAR SINGLY LINKED LIST
class CNode {
public:
    int data;
    CNode* next;
    CNode(int d) {
        data = d;
        next = NULL;
    }
};
void insertEndCSLL(CNode*& head, int d) {
    CNode* newNode = new CNode(d);
    if (!head) {
        head = newNode;
        head->next = head;
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}
void deleteEvenCSLL(CNode*& head) {
    if (!head) return;
    // Handle even head nodes
    while (head && head->data % 2 == 0) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        CNode* last = head;
        while (last->next != head)
            last = last->next;
        CNode* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
    }
    if (!head) return;
    CNode* curr = head->next;
    CNode* prev = head;
    while (curr != head) {
        if (curr->data % 2 == 0) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}
void printCSLL(CNode* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Circular Singly Linked List: ";
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    DNode* headDLL = NULL;
    DNode* tailDLL = NULL;
    CNode* headCSLL = NULL;
    int choice;
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Remove even nodes from Doubly Linked List\n";
        cout << "2. Remove even nodes from Circular Singly Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            int val;
            cout << "Enter value to insert (DLL): ";
            cin >> val;
            insertEndDLL(headDLL, tailDLL, val);
            deleteEvenDLL(headDLL);
            cout << "Even nodes removed from DLL.\n";
            printDLL(headDLL);
            break;
        case 2:
            int val;
            cout << "Enter value to insert (CSLL): ";
            cin >> val;
            insertEndCSLL(headCSLL, val);
            deleteEvenCSLL(headCSLL);
            cout << "Even nodes removed from CSLL.\n";
            printCSLL(headCSLL);
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
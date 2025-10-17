#include <iostream>
using namespace std;
struct Node {
    int coeff;
    int power;
    Node* next;
    Node(int c, int p) : coeff(c), power(p), next(NULL) {}
};
// Insert in sorted order descending by power (so we keep lists sorted)
void insert_sorted(Node** head_ref, int c, int p) {
    Node* new_node = new Node(c, p);
    if (*head_ref == NULL || (*head_ref)->power < p) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        Node* curr = *head_ref;
        while (curr->next != NULL && curr->next->power >= p) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}
// Add two polynomial lists (both sorted descending by power)
Node* addPoly(Node* a, Node* b) {
    Node* result = NULL;
    Node* tail = NULL;
    while (a != NULL && b != NULL) {
        if (a->power == b->power) {
            int c = a->coeff + b->coeff;
            int p = a->power;
            a = a->next;
            b = b->next;
            if (c != 0) {
                Node* nd = new Node(c, p);
                if (result == NULL) {
                    result = nd;
                    tail = nd;
                } else {
                    tail->next = nd;
                    tail = nd;
                }
            }
        }
        else if (a->power > b->power) {
            Node* nd = new Node(a->coeff, a->power);
            a = a->next;
            if (result == NULL) {
                result = nd;
                tail = nd;
            } else {
                tail->next = nd;
                tail = nd;
            }
        }
        else { 
            Node* nd = new Node(b->coeff, b->power);
            b = b->next;
            if (result == NULL) {
                result = nd;
                tail = nd;
            } else {
                tail->next = nd;
                tail = nd;
            }
        }
    }
    while (a != NULL) {
        Node* nd = new Node(a->coeff, a->power);
        a = a->next;
        if (result == NULL) {
            result = nd;
            tail = nd;
        } else {
            tail->next = nd;
            tail = nd;
        }
    }
    while (b != NULL) {
        Node* nd = new Node(b->coeff, b->power);
        b = b->next;
        if (result == NULL) {
            result = nd;
            tail = nd;
        } else {
            tail->next = nd;
            tail = nd;
        }
    }
    return result;
}
void printResult(Node* head) {
    cout << "[";
    Node* cur = head;
    bool first = true;
    while (cur != NULL) {
        if (!first) {
            cout << ", ";
        }
        first = false;
        cout << "[" << cur->coeff << ", " << cur->power << "]";
        cur = cur->next;
    }
    cout << "]";
}
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    // Sample: list1 = [[5, 2], [4, 1], [2, 0]]
    insert_sorted(&poly1, 5, 2);
    insert_sorted(&poly1, 4, 1);
    insert_sorted(&poly1, 2, 0);
    // Sample: list2 = [[5, 1], [5, 0]]
    insert_sorted(&poly2, 5, 1);
    insert_sorted(&poly2, 5, 0);
    Node* result = addPoly(poly1, poly2);
    printResult(result);
    cout << "\n";
    return 0;
}
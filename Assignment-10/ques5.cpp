#include <iostream>
#include <unordered_set>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
bool detectLoop(Node* head) {
    unordered_set<Node*> hash;
    Node* temp = head;
    while (temp != NULL) {
    if (hash.count(temp))
    return true; // loop detected
    hash.insert(temp);
    temp = temp->next;
    }
    return false;
}
Node* newNode(int data) {
Node* node = new Node(data);
return node;
}
int main() {
Node* head = newNode(1);
head->next = newNode(2);
head->next->next = newNode(3);
head->next->next->next = newNode(4);
head->next->next->next->next = head->next;//create loop
cout << (detectLoop(head) ? "true" : "false");
return 0;
}
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void displayCircular(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; 
}
int main() {
    int arr[] = {20,100,40,80,60};
    Node* head = NULL, *temp=NULL;
    for (int i=0;i<5;i++){
        Node* newNode = new Node{arr[i],NULL};
        if (!head){ head=newNode; temp=head; }
        else { temp->next=newNode; temp=newNode; }
    }
    temp->next=head;
    displayCircular(head);
}
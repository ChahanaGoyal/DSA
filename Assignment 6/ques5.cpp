#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp=head->next;
    while (temp && temp!=head)
        temp=temp->next;
    return (temp==head);
}
int main() {
    Node* a=new Node{1,NULL};
    Node* b=new Node{2,NULL};
    Node* c=new Node{3,NULL};
    a->next=b; b->next=c; c->next=a;
    if (isCircular(a)) cout<<"Circular List\n";
    else cout<<"Not Circular\n";
}
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
int sizeDoubly(Node* head) {
    int count=0;
    while (head){ count++; head=head->next; }
    return count;
}
int sizeCircular(Node* head) {
    if (!head) return 0;
    int count=0;
    Node* temp=head;
    do { count++; temp=temp->next; } while (temp!=head);
    return count;
}
int main() {
    // Doubly list
    Node* d1=new Node{10,NULL,NULL};
    Node* d2=new Node{20,NULL,d1}; d1->next=d2;
    Node* d3=new Node{30,NULL,d2}; d2->next=d3;
    cout<<"Size of doubly list: "<<sizeDoubly(d1)<<endl;
    // Circular list
    Node* c1=new Node{1,NULL,NULL};
    Node* c2=new Node{2,NULL,NULL};
    Node* c3=new Node{3,NULL,NULL};
    c1->next=c2; c2->next=c3; c3->next=c1;
    cout<<"Size of circular list: "<<sizeCircular(c1)<<endl;
}
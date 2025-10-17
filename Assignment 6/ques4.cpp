#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* next;
    Node* prev;
};
bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail=head;
    while (tail->next) tail=tail->next;
    while (head!=tail && tail->next!=head) {
        if (head->data != tail->data) return false;
        head=head->next;
        tail=tail->prev;
    }
    return true;
}
int main() {
    char str[]="madam";
    Node* head=NULL, *tail=NULL;
    for (int i=0;str[i]!='\0';i++){
        Node* n=new Node{str[i],NULL,NULL};
        if (!head){ head=tail=n; }
        else { tail->next=n; n->prev=tail; tail=n; }
    }
    if (isPalindrome(head)) cout<<"Palindrome\n";
    else cout<<"Not palindrome\n";
}
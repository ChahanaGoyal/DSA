#include <iostream>
using namespace std;
#define MAX 100
class Queue {
    int arr[MAX];
    int front, rear, count;
public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == MAX; }
    void enqueue(int x) {
        if (isFull()) return;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        count++;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front];
        front = (front + 1) % MAX;
        count--;
        return x;
    }
    int size() { return count; }
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};
class Stack {
    int arr[MAX];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    bool isEmpty() { return topIndex == -1; }
    bool isFull() { return topIndex == MAX - 1; }
    void push(int x) {
        if (isFull()) return;
        arr[++topIndex] = x;
    }
    int pop() {
        if (isEmpty()) return -1;
        return arr[topIndex--];
    }
    int top() {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }
};
bool checkSorted(Queue &q) {
    Stack st;
    int expected = 1;
    int n = q.size();
    while (!q.isEmpty()) {
        int front = q.dequeue();
        if (front == expected) {
            expected++;
        } else {
            if (!st.isEmpty() && st.top() < front) {
                return false; 
            }
            st.push(front);
        }
        while (!st.isEmpty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }
    return (expected - 1 == n);
}
int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    if (checkSorted(q))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
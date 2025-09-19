#include <iostream>
using namespace std;
const int MAXQ = 1000;
struct MyQueue {
    int arr[MAXQ];
    int frontIdx;
    int rearIdx;
    int size;
    MyQueue() {
        frontIdx = 0;
        rearIdx = -1;
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == MAXQ;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }
        rearIdx = (rearIdx + 1) % MAXQ;
        arr[rearIdx] = x;
        size++;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1; 
        }
        int val = arr[frontIdx];
        frontIdx = (frontIdx + 1) % MAXQ;
        size--;
        return val;
    }
    int front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[frontIdx];
    }
};
struct Stack_TwoQueues {
    MyQueue q1;
    MyQueue q2;
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            int v = q1.dequeue();
            q2.enqueue(v);
        }
        MyQueue temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack underflow in pop\n";
            return;
        }
        q1.dequeue();
    }
    int top() {
        if (q1.isEmpty()) {
            return -1;
        }
        return q1.front();
    }
    bool isEmpty() {
        return q1.isEmpty();
    }
};
struct Stack_OneQueue {
    MyQueue q;
    void push(int x) {
        q.enqueue(x);
        int cnt = q.size;
        for (int i = 0; i < cnt - 1; i++) {
            int v = q.dequeue();
            q.enqueue(v);
        }
    }
    void pop() {
        if (q.isEmpty()) {
            cout << "Stack underflow in pop\n";
            return;
        }
        q.dequeue();
    }
    int top() {
        if (q.isEmpty()) {
            return -1;
        }
        return q.front();
    }
    bool isEmpty() {
        return q.isEmpty();
    }
};
int main() {
    cout << "Stack implemented using Two Queues:\n";
    Stack_TwoQueues st2;
    st2.push(10);
    st2.push(20);
    st2.push(30);
    cout << "Top: " << st2.top() << "\n"; 
    st2.pop();
    cout << "Top after pop: " << st2.top() << "\n"; 
    cout << "\nStack implemented using One Queue:\n";
    Stack_OneQueue st1;
    st1.push(100);
    st1.push(200);
    st1.push(300);
    cout << "Top: " << st1.top() << "\n"; 
    st1.pop();
    cout << "Top after pop: " << st1.top() << "\n"; 
    return 0;
}
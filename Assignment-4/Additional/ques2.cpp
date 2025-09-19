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
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == MAX;
    }
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
    int size() {
        return count;
    }
    void display() {
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % MAX;
            cout << arr[idx];
            if (i != count - 1) cout << ", ";
        }
        cout << endl;
    }
    int minIndex(int n) {
        int min_index = -1;
        int min_val = 1e9;
        for (int i = 0; i < n; i++) {
            int curr = dequeue();
            if (curr <= min_val && i < n) {
                min_val = curr;
                min_index = i;
            }
            enqueue(curr); 
        }
        return min_index;
    }
    void moveMinToRear(int min_index, int n) {
        int min_val;
        for (int i = 0; i < n; i++) {
            int curr = dequeue();
            if (i == min_index) {
                min_val = curr; 
            } else {
                enqueue(curr);
            }
        }
        enqueue(min_val); 
    }
    void sortQueue() {
        for (int i = 1; i <= size(); i++) {
            int min_index = minIndex(size() - i + 1);
            moveMinToRear(min_index, size() - i + 1);
        }
    }
};
int main() {
    Queue q;
    q.enqueue(11);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(21);
    cout << "Original Queue: ";
    q.display();
    q.sortQueue();
    cout << "Sorted Queue: ";
    q.display();
    return 0;
}
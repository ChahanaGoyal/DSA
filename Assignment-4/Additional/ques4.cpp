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
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    int size() { return count; }
};
int countStudents(int students[], int sandwiches[], int n) {
    Queue q;
    for (int i = 0; i < n; i++) {
        q.enqueue(students[i]);
    }
    int index = 0;     
    int rotations = 0;   
    while (!q.isEmpty() && rotations < q.size()) {
        if (q.peek() == sandwiches[index]) {
            q.dequeue();
            index++;
            rotations = 0; 
        } else {
            int s = q.dequeue();
            q.enqueue(s);
            rotations++;
        }
    }
    return q.size(); 
}
int main() {
    int students[]   = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;
    cout << countStudents(students, sandwiches, n) << endl;
    return 0;
}
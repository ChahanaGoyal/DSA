#include <iostream>
#include <climits> 
using namespace std;
class MinStack {
private:
    long long *st;    
    int capacity;     
    int topIndex;     
    long long minEle;  
public:
    MinStack(int cap) {
        capacity = cap;
        st = new long long[capacity];
        topIndex = -1;
        minEle = 0;
    }
    ~MinStack() {
        delete[] st;
    }
    bool isEmpty() {
        return topIndex == -1;
    }
    bool isFull() {
        return topIndex == capacity - 1;
    }
    void push(long long x) {
        if (isFull()) {
            cout << "Stack Overflow, cannot push " << x << "\n";
            return;
        }
        if (isEmpty()) {
            topIndex++;
            st[topIndex] = x;
            minEle = x;
        }
        else if (x >= minEle) {
            topIndex++;
            st[topIndex] = x;
        }
        else {
            long long encoded = 2 * x - minEle;
            topIndex++;
            st[topIndex] = encoded;
            minEle = x;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow, cannot pop\n";
            return;
        }
        long long t = st[topIndex];
        if (t < minEle) {
            long long prevMin = 2 * minEle - t;
            minEle = prevMin;
        }
        topIndex--;
    }
    long long top() {
        if (isEmpty()) {
            cout << "Stack is empty, top not defined\n";
            return LLONG_MIN; 
        }
        long long t = st[topIndex];
        if (t >= minEle) {
            return t;
        }
        else {
            return minEle;
        }
    }
    long long getMin() {
        if (isEmpty()) {
            cout << "Stack is empty, min not defined\n";
            return LLONG_MIN; 
        }
        return minEle;
    }
};
int main() {
    MinStack s(100); 
    s.push(3);
    cout << "push 3, min = " << s.getMin() << "\n";
    s.push(5);
    cout << "push 5, min = " << s.getMin() << "\n";
    s.push(2);
    cout << "push 2, min = " << s.getMin() << "\n";
    s.push(1);
    cout << "push 1, min = " << s.getMin() << "\n";
    cout << "top = " << s.top() << ", min = " << s.getMin() << "\n";
    s.pop();
    cout << "after pop, min = " << s.getMin() << "\n";
    cout << "top = " << s.top() << "\n";
    s.pop();
    cout << "after pop, min = " << s.getMin() << "\n";
    s.push(0);
    cout << "push 0, min = " << s.getMin() << "\n";
    return 0;
}
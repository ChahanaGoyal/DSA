#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue {
    vector<int> data;
    int parent(int i) { return i / 2; }
    int leftChild(int i) { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }
    void siftUp(int i) {
        while (i > 0 && data[parent(i)] < data[i]) {
            swap(data[parent(i)], data[i]);
            i = parent(i);
        }
    }
    void siftDown(int i) {
        int n = data.size();
        while (true) {
            int l = leftChild(i);
            int r = rightChild(i);
            int largest = i;
            if (l < n && data[l] > data[largest]) largest = l;
            if (r < n && data[r] > data[largest]) largest = r;
            if (largest != i) {
                swap(data[i], data[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
public:
    bool empty() const {
        return data.empty();
    }
    int size() const {
        return (int)data.size();
    }
    void push(int value) {
        data.push_back(value);
        siftUp((int)data.size() - 1);
    }
    int top() const {
        if (data.empty()) {
            cout<<"Priority Queue is empty"<<endl;
        }
        return data.front();
    }
    int pop() {
        if (data.empty()) {
            cout<<"Priority Queue is empty"<<endl;
        }
        int result = data.front();
        data[0] = data.back();
        data.pop_back();
        if (!data.empty()) {
            siftDown(0);
        }
        return result;
    }
};
int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(4);
    pq.push(15);
    pq.push(8);
    cout << "Top is: " << pq.top() << endl;
    cout << "Popping: ";
    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
    cout << endl;
    return 0;
}
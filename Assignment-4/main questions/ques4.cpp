#include <iostream>
using namespace std;
#define MAX_CHARS 26
void firstNonRepeating(const char stream[], int n) {
    int freq[MAX_CHARS] = {0};
    int *queueArr = new int[n];
    int front = 0, rear = 0; 
    for (int i = 0; i < n; i++) {
        char ch = stream[i];
        int idx = ch - 'a';
        if (idx < 0 || idx >= MAX_CHARS) {
            cout << "-1 ";
            continue;
        }
        freq[idx]++;
        queueArr[rear++] = idx;
        while (front < rear && freq[ queueArr[front] ] > 1) {
            front++;
        }
        if (front == rear) {
            cout << "-1 ";
        } else {
            char out = 'a' + queueArr[front];
            cout << out << " ";
        }
    }
    delete[] queueArr;
    cout << "\n";
}
int main() {
    char s[] = {'a','a','b','c'};
    int n = sizeof(s)/sizeof(s[0]);
    firstNonRepeating(s, n); 
    return 0;
}
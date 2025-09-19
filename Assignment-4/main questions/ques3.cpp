#include <iostream>
using namespace std;
void interleaveFirstSecond(int arr[], int n, int result[]) {
    if (n % 2 != 0) {
        cout << "Array size must be even.\n";
        return;
    }
    int half = n / 2;
    int *stk = new int[half];
    int top = -1;
    for (int i = 0; i < half; ++i) {
        stk[++top] = arr[i];
    }
    int idxFirst = 0;
    int idxSecond = half;
    int idxRes = 0;
    while (idxFirst < half && idxSecond < n) {
        result[idxRes++] = stk[idxFirst++];
        result[idxRes++] = arr[idxSecond++];
    }
    delete[] stk;
}
int main() {
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *res = new int[n];
    interleaveFirstSecond(arr, n, res);
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
    delete[] res;
    return 0;
}
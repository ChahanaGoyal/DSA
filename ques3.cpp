#include <iostream>
#include <climits>
using namespace std;
void nextGreater(int arr[], int n, int res[]) {
    for (int i = 0; i < n; ++i) {
        res[i] = -1;
    }
    int *stackArr = new int[n];
    int top = -1; 
    for (int i = 0; i < n; ++i) {
        while (top >= 0 && arr[i] > arr[ stackArr[top] ]) {
            int idx = stackArr[top];
            top--;
            res[idx] = arr[i];
        }
        top++;
        stackArr[top] = i;
    }
    delete [] stackArr;
}
int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *res = new int[n];
    nextGreater(arr, n, res);
    cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " --> " << res[i] << "\n";
    }
    delete [] res;
    return 0;
}
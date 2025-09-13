#include <iostream>
using namespace std;
int findMinNotUsed(int A[], bool used[], int N) {
    int minVal = 0;
    bool found = false;
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            if (!found || A[i] < minVal) {
                minVal = A[i];
                found = true;
            }
        }
    }
    return minVal;
}
bool isStackSortable(int A[], int N) {
    bool *used = new bool[N];
    for (int i = 0; i < N; ++i) used[i] = false;
    int *stackArr = new int[N];
    int top = -1;
    int outputCount = 0;
    for (int i = 0; i < N; ++i) {
        stackArr[++top] = A[i];
        while (top >= 0) {
            int topVal = stackArr[top];
            int minNotUsed = findMinNotUsed(A, used, N);
            if (topVal == minNotUsed) {
                used[i] = false; 
                for (int k = 0; k < N; ++k) {
                    if (!used[k] && A[k] == topVal) {
                        used[k] = true;
                        break;
                    }
                }
                top--;
                outputCount++;
            }
            else {
                break;
            }
        }
    }
    while (top >= 0) {
        int topVal = stackArr[top];
        int minNotUsed = findMinNotUsed(A, used, N);
        if (topVal == minNotUsed) {
            for (int k = 0; k < N; ++k) {
                if (!used[k] && A[k] == topVal) {
                    used[k] = true;
                    break;
                }
            }
            top--;
            outputCount++;
        }
        else {
            break;
        }
    }
    bool result = (outputCount == N);
    delete[] used;
    delete[] stackArr;
    return result;
}
int main() {
    int A1[] = {4,1,3,2};
    int N1 = sizeof(A1)/sizeof(A1[0]);
    cout << (isStackSortable(A1, N1) ? "Yes\n" : "No\n");
    int A2[] = {4,2,3,1};
    int N2 = sizeof(A2)/sizeof(A2[0]);
    cout << (isStackSortable(A2, N2) ? "Yes\n" : "No\n");
    return 0;
}
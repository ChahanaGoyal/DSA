#include <iostream>
using namespace std;
void dailyTemperatures(int temps[], int n, int answer[]) {
    for (int i = 0; i < n; ++i) {
        answer[i] = 0;
    }
    int *stackArr = new int[n];
    int top = -1;
    for (int i = 0; i < n; ++i) {
        while (top >= 0 && temps[ stackArr[top] ] < temps[i]) {
            int prevIdx = stackArr[top];
            top--;
            answer[prevIdx] = i - prevIdx;
        }
        top++;
        stackArr[top] = i;
    }
    delete[] stackArr;
}
int main() {
    int temps[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temps) / sizeof(temps[0]);
    int *answer = new int[n];
    dailyTemperatures(temps, n, answer);
    cout << "Daily Temperatures Answer: ";
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << " ";
    }
    cout << "\n";
    delete[] answer;
    return 0;
}
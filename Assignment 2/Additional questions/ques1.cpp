#include <iostream>
using namespace std;
int countPairsDiffK(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    int arr[] = {1, 5, 2, 2, 2, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int result = countPairsDiffK(arr, n, k);
    cout << "Number of pairs with difference " << k << " is: " << result << endl;
    return 0;
}
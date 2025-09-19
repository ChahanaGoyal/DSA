#include <iostream>
using namespace std;
void duplicateTwos(int arr[], int n) {
    int i, j;
    int countTwos = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == 2) {
            countTwos++;
        }
    }
    i = n - 1;
    j = n + countTwos - 1;
    while (i >= 0) {
        if (j < n) {
            arr[j] = arr[i]; 
        }
        if (arr[i] == 2) {
            j--;
            if (j < n) {
                arr[j] = 2;
            }
        }
        i--;
        j--;
    }
}
int main() {
    int arr[] = {1, 2, 3, 2, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    duplicateTwos(arr, n);
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
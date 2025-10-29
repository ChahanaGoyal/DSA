#include <iostream>
using namespace std;
void bidirectionalSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int minIdx = left;
        int maxIdx = left;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIdx]) {
                minIdx = i;
            }
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        if (minIdx != left) {
            int temp = arr[left];
            arr[left] = arr[minIdx];
            arr[minIdx] = temp;
            if (maxIdx == left) {
                maxIdx = minIdx;
            }
        }
        if (maxIdx != right) {
            int temp = arr[right];
            arr[right] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
        left++;
        right--;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = { 64, 25, 12, 22, 11, 90, 3, 55 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    bidirectionalSelectionSort(arr, n);
    cout << "Sorted array:   ";
    printArray(arr, n);
    return 0;
}
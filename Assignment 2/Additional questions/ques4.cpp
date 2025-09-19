#include <iostream>
using namespace std;
void sort012(int arr[], int n) {
    int low = 0;      
    int mid = 0;      
    int high = n - 1;  
    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { 
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}
int main() {
    int arr[] = {0, 1, 2, 0, 1, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
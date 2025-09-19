#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0) {
        return 0;
    }
    int *A = new int[n];
    int *res = new int[n];  
    int *st = new int[n];    
    int top = -1;             
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        while (top >= 0 && st[top] >= A[i]) {
            top--;
        }
        if (top < 0) {
            res[i] = -1;  
        } else {
            res[i] = st[top];
        }
        st[++top] = A[i];
    }
    cout << "Nearest smaller elements to the left:\n";
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
    delete[] A;
    delete[] res;
    delete[] st;
    return 0;
}
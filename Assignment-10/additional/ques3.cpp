#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool areEqual(int a[], int b[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (freq.find(b[i]) == freq.end() || freq[b[i]] == 0) {
            return false;
        }
        freq[b[i]]--;
    }
    // Check all counts are zero
    for (auto &p : freq) {
        if (p.second != 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int a[] = {1, 2, 5, 4, 0};
    int b[] = {2, 4, 5, 0, 1};
    int n = sizeof(a)/sizeof(a[0]);
    if (areEqual(a, b, n))
        cout << "Yes, arrays are equal" << endl;
    else
        cout << "No, arrays are not equal" << endl;
    return 0;
}
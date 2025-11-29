#include <iostream>
#include <unordered_set>
using namespace std;
bool hasPairWithSum(int arr[], int n, int target) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int complement = target - x;
        if (seen.find(complement) != seen.end()) {
            return true;
        }
        seen.insert(x);
    }
    return false;
}
int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    if (hasPairWithSum(arr, n, target))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
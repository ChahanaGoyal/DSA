#include <iostream>
using namespace std;
void printBinary(int num) {
    int binary[32]; 
    int index = 0;
    while (num > 0) {
        binary[index++] = num % 2;
        num = num / 2;
    }
    for (int i = index - 1; i >= 0; i--) {
        cout << binary[i];
    }
}
void generateBinary(int n) {
    for (int i = 1; i <= n; i++) {
        printBinary(i);
        if (i != n) cout << ", "; 
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    generateBinary(n);
    return 0;
}
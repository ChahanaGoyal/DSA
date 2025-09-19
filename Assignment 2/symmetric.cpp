#include <iostream>
using namespace std;
int main() {
	int size;
	cout<<"Enter size of matrix:";
	cin>>size;
    int k = 0;
    int total = (size * (size + 1)) / 2;  
    int a[total];
    cout << "Enter elements (row major lower triangle)\n";
    for (int i = 0; i < total; i++) {
        cin >> a[i];
    }
    cout << "The symmetric matrix is:"<<endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i >= j) {
                cout << a[k] << " ";
                k++;
            } else {
                int index = (j * (j + 1)) / 2 + i;  
                cout << a[index] << " ";
            }
        }
        cout << endl;
    }
	return 0;
}
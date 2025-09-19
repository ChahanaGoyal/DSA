#include <iostream>
using namespace std;
void TriDiagonalMatrix(int a[], int n)
{
    int k = 0;
    cout << "The tridiagonal matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j == -1 || i == j || i - j == 1)
            {
                cout << a[k] << " ";
                k++;
            }
            else
                cout << "0" << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter size of matrix" << endl;
    cin >> n;
    int size = 3 * n - 2;
    int a[size];
    cout << "Enter elements to be entered" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    TriDiagonalMatrix(a, n);
    return 0;
}
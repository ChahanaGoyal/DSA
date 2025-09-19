#include <iostream>
using namespace std;
void UpperTriangularMatrix(int a[], int n)
{
    int k = 0;
    cout << "The lower triangular matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
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
    int size = n * (n + 1) / 2;
    int a[size];
    cout << "Enter elements to be entered" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    UpperTriangularMatrix(a, n);
    return 0;
}
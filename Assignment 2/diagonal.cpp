#include <iostream>
using namespace std;
void DiagonalMatrix(int a[], int n)
{
    cout << "The diagonal matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << a[i] << " ";
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
    int a[n];
    cout << "Enter elements to be entered" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    DiagonalMatrix(a, n);
    return 0;
}
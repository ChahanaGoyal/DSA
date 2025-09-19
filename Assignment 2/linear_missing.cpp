#include <iostream>
using namespace std;
int linear(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return (i + 1);
        }
    }
}
int main()
{
    int arr[5] = {1, 3, 4, 5, 6};
    cout << "The missing number is:" << linear(arr, 5);
    return 0;
}
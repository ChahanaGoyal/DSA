#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}
void print(int arr[], int n)
{
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}
int main()
{
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr, 7);
    print(arr, 7);
    return 0;
}
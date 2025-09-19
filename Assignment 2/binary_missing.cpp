#include <iostream>
using namespace std;
int binary(int arr[], int n, int s, int e)
{
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == mid + 1)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s + 1;
}
int main()
{
    int arr[5] = {1, 3, 4, 5, 6};
    cout << "The missing number is:" << binary(arr, 5, 0, 4);
    return 0;
}
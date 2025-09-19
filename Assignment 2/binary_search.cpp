#include <iostream>
using namespace std;
int binary(int arr[], int n, int key, int s, int e)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int key = 2;
    int location = binary(arr, 5, 2, 0, 4);
    cout << location;
    return 0;
}
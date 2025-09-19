#include <iostream>
using namespace std;
void inverse(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                inv_count++;
        }
    }
    cout << "The number of inversions in the given array are " << inv_count << endl;
}
int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements in array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    inverse(arr, n);
    return 0;
}
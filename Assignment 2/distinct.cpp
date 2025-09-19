#include <iostream>
using namespace std;
void distinct(int arr[], int n)
{
    int unique_count = 0;
    for (int i = 0; i < n; i++)
    {
        bool unique = true;
        if (arr[i] == -3874686)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                unique = false;
                arr[i] = arr[j] = -3874686;
                break;
            }
        }
        if (unique == true)
            unique_count++;
    }
    cout << "The number of distinct elements in the given array are " << unique_count << endl;
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
    distinct(arr, n);
    return 0;
}
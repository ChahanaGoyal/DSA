#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size of array:" << endl;
    cin >> size;
    int arr[100];
    int index;
    cout << "Enter " << size << " elements in array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < size; j++)
    {
        bool same = false;
        for (int k = j + 1; k < size; k++)
        {
            if (arr[j] == arr[k])
            {
                same = true;
                index = j;
                break;
            }
        }
        if (same == true)
        {
            for (int m = index; m < size-1; m++)
            {
                arr[m] = arr[m + 1];
            }
            size = size - 1;
        }
    }
    cout << "The array with duplicate elements removed is:" << endl;
    for (int l = 0; l < size; l++)
    {
        cout << arr[l] << " ";
    }
    return 0;
}
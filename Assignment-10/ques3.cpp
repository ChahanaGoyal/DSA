#include <iostream>
#define MAX 1000
using namespace std;
void countFrequency(int arr[], int n)
{
    int hash[MAX] = {0}; // key = element, value = count
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
    for (int i = 0; i < MAX; i++)
    {
        if (hash[i] > 0)
            cout << i << "->" << hash[i] << " times" << endl;
    }
}
int main()
{
    int arr[] = {2, 3, 2, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFrequency(arr, n);
    return 0;
}
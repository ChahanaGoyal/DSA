#include <iostream>
#define MAX 1000
using namespace std;
void countFrequency(int arr[], int n)
{
    int hash[MAX] = {0}; // key = element, value = count
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1){
            cout << arr[i] << endl;
            break;
        }
    }
}
int main()
{
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFrequency(arr, n);
    return 0;
}
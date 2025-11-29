#include <iostream>
#include <limits.h>
#define MAX 1000
using namespace std;
void maxFrequency(int arr[], int n)
{
  int hash[MAX] = {0}; // key = element, value = count
  int maxcount = INT_MIN, maxvalue = INT_MIN;
  for (int i = 0; i < n; i++)
    hash[arr[i]]++;
  for (int i = 0; i < MAX; i++)
  {
    if (hash[i] >= maxcount)
    {
      maxcount = hash[i];
      maxvalue = i;
    }
    else if (hash[i] == maxcount)
    {
      if (i > maxvalue)
      {
        maxvalue = i;
      }
    }
  }
  cout << "Maximum frequency element is " << maxvalue << endl;
}
int main()
{
  int arr[] = {2, 3, 4, 3, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  maxFrequency(arr, n);
  return 0;
}
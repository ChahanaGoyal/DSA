#include <iostream>
#define MAX 100000
using namespace std;
bool containsDuplicate(int nums[], int n)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        if (hash[nums[i]] == 1)
            return true;
        hash[nums[i]] = 1;
    }
    return false;
}
int main()
{
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << containsDuplicate(nums, n) ? "true" : "false";
    return 0;
}
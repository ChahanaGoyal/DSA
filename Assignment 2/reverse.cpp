#include <iostream>
using namespace std;
void reverse(char *str)
{
    int size1 = 0;
    int k = 0;
    while (str[k] != '\0')
    {
        k++;
        size1++;
    }
    int i = 0, j = size1 - 1;
    while (i <= j)
    {
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    for (int l = 0; l < size1; l++)
    {
        cout << str[l];
    }
}
int main()
{
    char str[] = "Hello";
    reverse(str);
    return 0;
}
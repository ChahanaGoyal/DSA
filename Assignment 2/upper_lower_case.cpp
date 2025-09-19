#include <iostream>
using namespace std;
void convertCase(char *str)
{
    int size1 = 0;
    int k = 0;
    while (str[k] != '\0')
    {
        k++;
        size1++;
    }
    for (int i = 0; i < size1; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else
            str[i] -= 32;
    }
    for (int j = 0; j < size1; j++)
    {
        cout << str[j];
    }
}
int main()
{
    char str[] = "Hello";
    convertCase(str);
    return 0;
}
#include <iostream>
using namespace std;
void print(char *str3, int size3)
{
    for (int i = 0; i < size3; i++)
    {
        cout << str3[i];
    }
}
void concatenate(char *str1, char *str2)
{
    int size1 = 0;
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        i++;
        size1++;
    }
    int size2 = 0;
    while (str2[j] != '\0')
    {
        j++;
        size2++;
    }
    int size3 = 0;
    char str3[size1 + size2];
    for (int k = 0; k < size1; k++)
    {
        str3[size3] = str1[k];
        size3++;
    }
    for (int k = 0; k < size2; k++)
    {
        str3[size3] = str2[k];
        size3++;
    }
    print(str3, size3);
}
int main()
{
    char str1[] = "Hello";
    char str2[] = "World";
    concatenate(str1, str2);
    return 0;
}
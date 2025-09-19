#include <iostream>
using namespace std;
char toLowerCase(char str[], int n)
{
    if (str[n] >= 'a' && str[n] <= 'z')
        return str[n];
    else
    {
        char temp = str[n] - 'A' + 'a';
        return temp;
    }
}
void sort(char *str)
{
    int size1 = 0;
    int k = 0;
    while (str[k] != '\0')
    {
        k++;
        size1++;
    }
    for (int i = 0; i < size1 - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < size1 - i - 1; j++)
        {
            if (toLowerCase(str, j) > toLowerCase(str, (j + 1)))
            {
                swap(str[j], str[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
    for (int l = 0; l < size1; l++)
    {
        cout << str[l];
    }
}
int main()
{
    char str[] = "Hello";
    sort(str);
    return 0;
}
#include <iostream>
using namespace std;
int isVowel(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + ('a' - 'A'); // convert uppercase to lowercase
    }
    return (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u');
}
void deletevowel(char *str)
{
    int read = 0, write = 0;
    while (str[read] != '\0')
    {
        if (!isVowel(str[read]))
        {
            str[write++] = str[read]; // copy consonants (and non-letters)
        }
        read++;
    }
    str[write] = '\0'; // terminate the string
    for (int i = 0; i < write; i++)
    {
        cout << str[i];
    }
}
int main()
{
    char str[] = "Hello";
    deletevowel(str);
    return 0;
}
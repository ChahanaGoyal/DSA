#include <iostream>
#include <cstring> 
using namespace std;
bool areAnagrams(const char* str1, const char* str2) {
    int freq1[26] = {0}; 
    int freq2[26] = {0}; 
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 != n2) return false; 
    for (int i = 0; i < n1; i++) {
        freq1[str1[i] - 'a']++;
        freq2[str2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) return false;
    }
    return true;
}
int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}
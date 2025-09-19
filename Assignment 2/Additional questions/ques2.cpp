#include <iostream>
using namespace std;
bool canSplitString(const string& s) {
    int freq[26] = {0};
    for (int i=0;i<s.length();i++) {
        char ch=s[i];
        freq[ch - 'a']++;
        if (freq[ch - 'a'] > 1) {
            return true;
        }
    }
    return false; 
}
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    if (canSplitString(s)) {
        cout << "Yes, the string can be split into three parts as required." << endl;
    } else {
        cout << "No, it is not possible to split the string." << endl;
    }
    return 0;
}
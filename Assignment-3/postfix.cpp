#include<iostream>
#include<stack>
#include<string>
using namespace std;
int postfixEval(string &s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
    if(ch>='0' && ch<='9') st.push(ch-'0');
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (st.size() < 2) {
                cout << "Error: Insufficient operands." << endl;
                return -1;
            }
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/':
                    if (val2 == 0) {
                        cout << "Error: Division by zero." << endl;
                        return -1;
                    }
                    result = val1 / val2; break;
            }
            st.push(result);
        }
    }
    if (st.size() != 1) {
        cout << "Error: Invalid postfix expression." << endl;
        return -1;
    }
    return st.top();
}
int main(){
    string s;
    cout<<"Enter the postfix expression:";
    getline(cin,s);
    cout<<postfixEval(s);
    return 0;
}
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void infixToPostfix(string &s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch>='A' && ch<='Z') cout<<ch<<" ";
        else if(ch=='(') st.push(ch);
        else if(ch==')'){
            while(!st.empty() && st.top()!='('){
                cout<<st.top()<<" ";
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } 
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            while(!st.empty() && precedence(st.top())>=precedence(ch)){
                cout<<st.top()<<" ";
                st.pop();
            }
            st.push(ch);
        }
        else{
            cout<<"Invalid character "<<ch<<" in expression"<<endl;
            return;
        }
}
while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main(){
    string s;
    cout<<"Enter the expression:";
    getline(cin,s);
    infixToPostfix(s);
    return 0;
}
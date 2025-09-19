#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isBalancedParenthesis(string st){
    stack<char> s;
    for(int i=0;i<st.length();i++){
        char ch=st[i];
        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.top();
                if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()) return true;
    else return false;
}
int main(){
    string s;
    cout<<"Enter the parenthesis:";
    getline(cin,s);
    bool check=isBalancedParenthesis(s);
    if(check==true) cout<<"Balanced parenthesis";
    else cout<<"Unbalanced parenthesis";
    return 0;
}
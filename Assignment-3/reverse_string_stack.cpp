#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string:";
    getline(cin,str);
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        s.push(ch);
    }
    string reverse;
    while(!s.empty()){
        char ch=s.top();reverse.push_back(ch);
        s.pop();
    }
    cout<<"The reversed string is:"<<reverse<<endl;
    return 0;
}
// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string s){
    int n = s.size();
    if(n == 0) return true;
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else{
            if(s[i]==')' && st.top()=='(') st.pop();
            else if(s[i]=='}' && st.top()=='{') st.pop();
            else if(s[i]==']' && st.top()=='[') st.pop();
        }
    }
    if(st.empty()) return true;
    return false;
}

int main(){
    string s = "(){()}[][()]{}";
    bool b = isBalanced(s);
    if(b)   cout<<"Balanced";
    else cout<<"Not balanced";
}
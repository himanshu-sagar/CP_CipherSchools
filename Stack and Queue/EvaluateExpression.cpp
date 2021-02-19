// https://www.geeksforgeeks.org/expression-evaluation/

#include <bits/stdc++.h>
using namespace std;

int evaluate(vector<string> v)
{
    stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
        {
            int v1 = s.top(); 
            s.pop();
            int v2 = s.top(); 
            s.pop();
            if (v[i] == "+")
                s.push(v2 + v1);
            else if (v[i] == "-")
                s.push(v2 - v1);
            else if (v[i] == "*")
                s.push(v2 * v1);
            else if (v[i] == "/")
                s.push(v2 / v1);
        }
        else
            s.push(stoi(v[i]));
    }
    return s.top();
}

int main(){
    vector<string> v = {"10","2","+","6","*"};
    int res = evaluate(v);
    cout<<res;
}
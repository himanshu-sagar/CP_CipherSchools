#include<bits/stdc++.h>
using namespace std;
void generateParenthesisHelper(vector<string> &result,int open,int close,int n,string str)
{
    if(open<0 || close<0 || open>n || close>n || close>open)
        return;
    if(open==n && close==n)
    {
        result.push_back(str);
        return;
    }
    generateParenthesisHelper(result,open+1,close,n,str+"(");
    generateParenthesisHelper(result,open,close+1,n,str+")");
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    generateParenthesisHelper(result,0,0,n,"");
    return result;
}
int main()
{
    vector<string> result=generateParenthesis(5);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
}

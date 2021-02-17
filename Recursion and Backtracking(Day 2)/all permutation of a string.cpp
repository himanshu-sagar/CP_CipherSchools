#include<bits/stdc++.h>
using namespace std;

void generatePermutations(vector<string>&result,int start,int end,string str)
{
    if(start>=end)
    {
        result.push_back(str);
        return;
    }
    for(int i=start;i<=end;i++)
    {
        swap(str[i],str[start]);
        generatePermutations(result,start+1,end,str);
        //backtracking
        swap(str[i],str[start]);
    }
}
vector<string> permutations(string str)
{
    vector<string> result;
    generatePermutations(result,0,str.size()-1,str);
    return result;
}

void permutations1(string str,int start=0)
{
    if(start==str.length()-1)
    {
        cout<<str<<endl;
        return;
    }
    for(int i=start;i<str.length();i++)
    {
        swap(str[i],str[start]);
        permutations1(str,start+1);
        swap(str[i],str[start]);
    }
}

int main()
{
    string str="abc";
    vector<string> res=permutations(str);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }
    cout<<endl;
    permutations1(str);
}

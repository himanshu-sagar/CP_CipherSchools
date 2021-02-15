#include<bits/stdc++.h>
using namespace std;
void Sort01(vector<int>& vec)
{
    int s=0,e=vec.size()-1;
    while(s<=e)
    {
        while(vec[s]==0)
        {
            s++;
        }
        while(vec[e]==1)
        {
            e--;
        }
        if(s<=e)
        {
            swap(vec[s],vec[e]);
            s++;
            e--;
        }
    }
}
int main()
{
    vector<int> vec={0,1,1,1,0,0,0,1,1};
    Sort01(vec);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<"  ";
    }
}

#include<bits/stdc++.h>
using namespace std;
void alternateSort(vector<int> vec)
{

    sort(vec.begin(),vec.end());
    int i=0,j=vec.size()-1;
    while(i<j)
    {
        cout<<vec[j]<<" ";
        cout<<vec[i]<<" ";
        i++;
        j--;
    }
    if(vec.size()%2!=0)
        cout<<vec[i]<<" ";
}
int main()
{
    vector<int> vec={2,7,4,3,1,8,9};
    alternateSort(vec);
}


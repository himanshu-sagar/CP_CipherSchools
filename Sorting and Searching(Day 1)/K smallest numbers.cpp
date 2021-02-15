#include<bits/stdc++.h>
using namespace std;
void kSmallest(vector<int> vec,int k)
{
    sort(vec.begin(),vec.end());
    k=k-1;
    while(k>=0)
    {
        cout<<vec[k]<<" ";
        k--;
    }
}
int main()
{
    vector<int> vec={2,7,4,3,1,8,9};
    kSmallest(vec,3);
}


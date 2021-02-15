#include<bits/stdc++.h>
using namespace std;
int minimumPlatform(vector<int> arr,vector<int> dept)
{
    int i=1,j=0;
    int minPlatform=1,currPlatform=1;
    sort(arr.begin(),arr.end());
    sort(dept.begin(),dept.end());
    while(i<arr.size() && j<dept.size())
    {
        if(arr[i]>=dept[j])
        {
            currPlatform--;
            j++;
        }
        else
        {
            currPlatform++;
            i++;
        }
        minPlatform=max(minPlatform,currPlatform);
    }
    return minPlatform;
}
int main()
{
    vector<int> arr = { 900, 940, 950, 1100, 1500, 1800 };
    vector<int> dept = { 910, 1200, 1120, 1130, 1900, 2000 };
    cout<<minimumPlatform(arr,dept);
}

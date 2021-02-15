#include<bits/stdc++.h>
using namespace std;
int largestContiguousSum(vector<int> vec)
{
    int currsum=vec[0],maxsum=vec[0];
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]>vec[i]+currsum)
        {
            currsum=vec[i];
        }
        else
        {
            currsum=vec[i]+currsum;
        }
        maxsum=max(currsum,maxsum);
    }
    return maxsum;
}

int main()
{
    vector<int> vec={2,3,6,-20,3,4,8,9};
    cout<<largestContiguousSum(vec);
}

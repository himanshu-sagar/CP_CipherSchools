#include<bits/stdc++.h>
using namespace std;
int trappingRainWater(vector<int> &vec)
{   int size=vec.size();
    vector<int> leftmax(size),rightmax(size);
    leftmax[0]=vec[0];
    for(int i=1;i<size;i++)
    {
        leftmax[i]=max(leftmax[i-1],vec[i]);
    }
    rightmax[size-1]=vec[size-1];
    for(int j=size-2;j>=0;j--)
    {
        rightmax[j]=max(rightmax[j+1],vec[j]);
    }
    int countwater=0;
    for(int i=0;i<size;i++)
    {
        countwater+=(min(leftmax[i],rightmax[i])-vec[i]);
    }
    return countwater;
}
int main()
{
    vector<int> vec={1,4,2,3,5,2,1,3};
    cout<<trappingRainWater(vec);
}

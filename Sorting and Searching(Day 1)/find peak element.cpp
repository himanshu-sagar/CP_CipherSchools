#include<bits/stdc++.h>
using namespace std;
//Naive Approach
//time: O(n)    space:O(1)
int peakElement1(vector<int> vec)
{
    int n=vec.size();
    if(n==1)
    {
        return vec[0];
    }
    if(n>1)
    {
        if(vec[0]>vec[1])
            return vec[0];
        if(vec[n-1]>vec[n-2])
            return vec[n-1];
    }
    for(int i=1;i<n-2;i++)
    {
        if(vec[i]>vec[i-1] && vec[i]>vec[i+1])
        {
            return vec[i];
        }
    }
    return -1;
}
//divide and conquer
// time: O(logn)    space: O(1)
int peakElement1Helper(vector<int> &vec,int start,int end,int n)
{
    int mid=start+(end-start)/2;
    if((mid==0 || vec[mid-1]<=vec[mid]) && (mid==n-1 || vec[mid+1]<=vec[mid]))
        return mid;
    else if(mid>0 && vec[mid]<vec[mid-1])
        return peakElement1Helper(vec,start,mid-1,n);
    else
        return peakElement1Helper(vec,mid+1,end,n);
}
int peakElement2(vector<int> &vec)
{
    int peak=peakElement1Helper(vec,0,vec.size()-1,vec.size());
    return vec[peak];
}
int main()
{
    vector<int> vec={10, 20, 15, 2, 23, 90, 67};
    cout<<peakElement2(vec);
}

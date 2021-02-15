#include<bits/stdc++.h>
using namespace std;
//Naive
// time: O(n)   space: O(1);
pair<int,int> findFirstAndLast(const vector<int> &vec,int x)
{
    int first=-1,last=-1;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]!=x)
            continue;
        if(first==-1)
            first=i;
        else
            last=i;
    }

    return pair<int,int>(first,last);

}
//using binary search
//time: O(logn)  space: O(logn)
int findFirst(const vector<int> &vec,int x,int start, int end,int n)
{
    if(start<=end)
    {
    int mid=start+(end-start)/2;
    if((mid==0 || vec[mid-1]<x) && vec[mid]==x)
        return mid;
    else if(x>vec[mid])
        return findFirst(vec,x,(mid+1),end,n);
    else
        return findFirst(vec,x,start,mid-1,n);
    }
    return -1;
}
int findLast(const vector<int> &vec,int x,int start, int end,int n)
{
    if(start<=end)
    {

    int mid=start+(end-start)/2;
    if((mid==n-1 || vec[mid+1]>x) && vec[mid]==x)
        return mid;
    else if(x<vec[mid])
        return findLast(vec,x,start,(mid-1),n);
    else
        return findLast(vec,x,(mid+1),end,n);
    }
    return -1;
}

pair<int,int> findFirstAndLast1(const vector<int> &vec,int x)
{
    int n=vec.size();
    int first=findFirst(vec,x,0,n-1,n);

    int last=findLast(vec,x,0,n-1,n);
    return pair<int,int>(first,last);
}

int main()
{
    vector<int> vec={1,2,3,3,3,3,4,4};
    pair<int,int> ans= findFirstAndLast1(vec,3);
    cout<<"first: "<<ans.first<<" last: "<<ans.second<<endl;


}

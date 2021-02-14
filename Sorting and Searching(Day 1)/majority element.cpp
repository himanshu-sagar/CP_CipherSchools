#include<bits/stdc++.h>
using namespace std;
//Naive approach : time: O(n^2)  space: O(1)
int majorityElement1(vector<int> vec)
{

    for(int i=0;i<vec.size();i++)
    {
        int cnt=0;
        for(int j=0;j<vec.size();j++)
        {
            if(vec[i]==vec[j])
                cnt++;
        }
        if(cnt>vec.size()/2)
        {
            return vec[i];
        }
    }
    return -1;
}
//Moore's voting algorithm
// time: O(n)   space: O(1)
int getCandidate(vector<int> &vec)
{

    int candidateIndex=0,count=1;
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]==vec[candidateIndex])
            count++;
        else
            count--;

        if(count==0)
        {
            candidateIndex=i;
            count=1;
        }
    }
    return candidateIndex;
}
int findMajority2(vector<int> &vec)
{
    int candidateIndex=getCandidate(vec);
    int freq=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]==vec[candidateIndex])
        {
            freq++;
        }
    }
    if(freq>vec.size()/2)
    {
        cout<<vec[candidateIndex]<<" ";
    }
    else
    {
        cout<<" No candidateIndex Found"<<endl;
    }
}
int main()
{
    vector<int>vec={1,1,2,3,1,1,6,1,1};
    cout<<majorityElement1(vec)<<endl;

    findMajority2(vec);
}

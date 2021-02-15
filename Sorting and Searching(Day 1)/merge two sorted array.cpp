#include<bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSortedArr(const vector<int> &first,const vector<int> &second)
{
    int i=0,j=0,k=0;
    vector<int> result(first.size()+ second.size());
    while(i<first.size() && j<second.size())
    {
        if(first[i]<=second[j])
        {
            result[k]=(first[i]);
            i++;
        }
        else
        {
            result[k]=(second[j]);
            j++;
        }
        k++;
    }
    while(i<first.size())
    {
        result[k]=first[i];
        i++;
        k++;
    }
    while(j<second.size())
    {
        result[k]=second[j];
        j++;
        k++;
    }
    return result;
}

int main()
{
    vector<int> first={2,3,4,7,9,13};
    vector<int> second={1,5,6,10,19,20};
    vector<int> result=mergeTwoSortedArr(first,second);
    cout<<"Merging using vector: "<<endl;
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<"  ";
    }

}


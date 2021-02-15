#include<bits/stdc++.h>
using namespace std;
/*
pair<int,int> findElement(vector<vector<int>> matrix,int x)
{
    for(int i=0;i<matrix.size();i++)
    {
        int j=binarySearch(matrix[i],0,matrix[i].size()-1,x);
        if(j>=0)
        {
            return pair<int,int>(i,j);
        }
    }
}
*/
//Divide and conquer
//time: O(m+n)  space: O(1)
pair<int,int> findElement(const vector<vector<int>> matrix,int x)
{
    int m=matrix.size();
    int n=matrix[0].size();
    cout<<m<<"  "<<n<<endl;

    int smallest=matrix[0][0];
    int largest=matrix[m-1][n-1];

    if(smallest>x || largest<x || m==0 || n==0)
    {
        return pair<int,int>(-1,-1);
    }
    int i=0,j=n-1;
    while(i<m && j>=0)
    {
        if(matrix[i][j]==x)
        {
            return pair<int,int>(i,j);
        }

        else if(matrix[i][j]>x)
        {
            j--;
        }

        else
        {
            i++;
        }
    }
}

int main()
{
    vector<vector<int>> matrix= { { 10, 20, 30, 40,60 },
                                  { 15, 25, 35, 45,70 },
                                  { 27, 29, 37, 48,80 },
                                  { 32, 33, 39, 50,90 } };
    pair<int,int> ans=findElement(matrix,29);
    cout<<ans.first<<"   "<<ans.second;
}

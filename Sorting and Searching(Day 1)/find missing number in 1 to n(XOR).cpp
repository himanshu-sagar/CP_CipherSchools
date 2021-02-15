#include<bits/stdc++.h>
using namespace std;
//time: O(n)    space: O(1)
int missingNumber(vector<int> vec)
{
    int n=vec.size();
    int x1 = vec[0];
    int x2 = 1;

    for (int i = 1; i < n; i++)
        x1 = x1 ^ vec[i];

    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;

    return (x1 ^ x2);
}
int main()
{
    vector<int> vec={1,2,3,5,6,7,8,9,10};
    cout<<missingNumber(vec);
}

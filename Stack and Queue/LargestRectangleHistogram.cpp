// https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/


#include<bits/stdc++.h>
using namespace std;


int largestHist(vector<int>& h)
{
    int a = 0, m = 0, t = 0, i = 0, n = h.size();
    stack<int> s;
    while  (i < n)
    {
        if (s.empty() || h[s.top()] <= h[i])
            s.push(i++);
        else
        {
            t = s.top(); 
            s.pop();
            if (s.empty())
                a = h[t] * i;
            else
                a = h[t] * (i - s.top() - 1);

            m = max(m, a);
        }
    }
    while (!s.empty())
    {
        t = h[s.top()]; 
        s.pop();
        if (s.empty())
            a = h[t] * i;
        else
            a = h[t] * (i - s.top() - 1);
        m = max(m, a);
    }
    return m;
}


int main(){
    vector<int> v = {6,1,5,4,5,2,6};
    cout<<largestHist(v);
}
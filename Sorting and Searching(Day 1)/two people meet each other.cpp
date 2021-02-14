#include<bits/stdc++.h>
using namespace std;

// time: O(n)   space: O(1)
bool checkMeeting(int a,int jump1,int b,int jump2)
{
    if(a>b && jump1>=jump2)
        return false;
    if(b>a && jump2>=jump1)
        return false;

    if(a<b)
    {
        swap(a,b);
        swap(jump1,jump2);
    }
    while(a>=b)
    {
        if(a==b)
        {
            return true;
        }
        a=a+jump1;
        b=b+jump2;
    }
    return false;
}
// time: O(1)   space: O(1)
bool checkMeeting1(int a,int jump1,int b,int jump2)
{
    if(a>b && jump1>=jump2)
        return false;
    if(b>a && jump2>=jump1)
        return false;

    if(a<b)
    {
        swap(a,b);
        swap(jump1,jump2);
    }
    return (a-b)%(jump2-jump1)==0;
}
int main()
{
    cout<<checkMeeting1(6,6,4,9);
}

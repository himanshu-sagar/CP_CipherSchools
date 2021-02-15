#include<bits/stdc++.h>
using namespace std;
void Sort012(vector<int>& vec)
{
    int zp=0,op=0,tp=vec.size()-1;
    while(op<=tp)
    {
        switch(vec[op])
        {
        case 0:
            swap(vec[zp],vec[op]);
            zp++;
            op++;
            break;
        case 1:
            op++;
            break;
        case 2:
            swap(vec[tp],vec[op]);
            tp--;
            break;
        }
    }
}

int main()
{
    vector<int> vec={0,1,2,2,2,0,0,1,1};
    Sort012(vec);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<"  ";
    }
}

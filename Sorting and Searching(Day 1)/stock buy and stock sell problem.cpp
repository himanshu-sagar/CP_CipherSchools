#include<bits/stdc++.h>
using namespace std;
//for single time buy and sell
int  stockbuysell1(vector<int> &stockPrice)
{
    int minval=stockPrice[0],profit=0;
    for(int i=1;i<stockPrice.size();i++)
    {
        if(minval<=stockPrice[i])
        {
            int tempProfit=stockPrice[i]-minval;
            profit=max(tempProfit,profit);
        }
        else
            minval=stockPrice[i];
    }
    return profit;
}
// for multiple transactions
int  stockbuysell2(vector<int> &stockPrice)
{
    int profit=0;
    for(int i=1;i<stockPrice.size();i++)
    {
        if(stockPrice[i-1]<=stockPrice[i])
        {
                profit+=stockPrice[i]-stockPrice[i-1];
        }
    }
    return profit;
}
int main()
{
    vector<int> stockPrice={1,5,3,12};
    cout<<stockbuysell2(stockPrice);
}



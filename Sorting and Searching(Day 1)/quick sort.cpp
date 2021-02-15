#include<iostream>
using namespace std;

int partitionQ(int arr[],int si,int ei)
{
    int pivot=arr[ei];
    int pindex=si-1;
    for(int i=si;i<ei;i++)
    {
        if(arr[i]<=pivot)
        {
            pindex++;
            int temp=arr[pindex];
            arr[pindex]=arr[i];
            arr[i]=temp;
        }
    }
    int temp1=arr[pindex+1];
    arr[pindex+1]=arr[ei];
    arr[ei]=temp1;

    return pindex+1;
}
void QuickSort(int arr[],int si,int ei)
{
    if(ei-si<=0)
    {
        return;
    }
    int pivot=partitionQ(arr,si,ei);
    QuickSort(arr,si,pivot-1);
    QuickSort(arr,pivot+1,ei);

}
int main()
{
    int arr[10]={23,2,344,0,34,-1,3,55,343};
    int n=sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
}

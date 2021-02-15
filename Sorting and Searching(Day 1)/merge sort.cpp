#include<iostream>
using namespace std;
void mergeTwoSortedArr(int temp1[],int n1,int temp2[],int n2,int arr[])
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if (temp1[i]<=temp2[j])
        {
            arr[k]=temp1[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=temp2[j];
            k++;
            j++;
        }
    }

    while(i<n1)
    {
        arr[k]=temp1[i];
        k++;
        i++;
    }

    while(j<n2)
    {
        arr[k]=temp2[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[],int size)
{
    if(size==1)
	{
		return;
	}
    int *part1=new int [size/2];
    int size1=size/2;
    int *part2=new int [size-size/2];
    int size2=size-size/2;
    for(int i=0; i<size1; i++)
    {
        part1[i]=arr[i];
    }
    int k=0;
    for(int i=size1; i<size;i++)
    {
        part2[k++]=arr[i];
    }
    mergeSort(part1, size1);
    mergeSort(part2, size2);
    mergeTwoSortedArr(part1, size1, part2, size2, arr);
}

int main()
{
    int arr[]={1,100000,5,2487,9,255,89,54};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
}

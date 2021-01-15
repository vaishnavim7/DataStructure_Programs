#include<iostream>
#include<stdio.h>
using namespace std;

void InsertionSort(int arr[], int limit)
{
    int temp, i, j;
    for(i = 1; i<limit; i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j = j-1;;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int limit;
    int arr[limit];
    cout<<"Enter the size of array:"<<endl;
    cin>>limit;

    cout<<"Enter the elements of array:"<<endl;
    for(int i = 0; i<limit; i++)
    {
        cin>>arr[i];
    }

    cout<<endl<<"The elements of array before sorting:"<<endl;
    for(int i = 0; i<limit; i++)
    {
        cout<<arr[i]<<endl;
    }

    cout<<endl<<"The elements of array after insertion sorting:"<<endl;
    InsertionSort(arr, limit);
    for(int i = 0; i<limit; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}




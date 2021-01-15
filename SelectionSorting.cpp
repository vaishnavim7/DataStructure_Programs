#include<iostream>
#include<stdio.h>
using namespace std;

void SelectionSort(int arr[], int limit)
{
    int temp, mn;
    for(int i = 0; i<limit-1; i++)
    {
        mn = i;
        for(int j = i+1; j<limit; j++)
        {
            if(arr[j]< arr[mn])
            {
                mn = j;
            }
            temp = arr[i];
            arr[i] = arr[mn];
            arr[mn] = temp;
        }
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

    cout<<endl<<"The elements of array after selection sorting:"<<endl;
    SelectionSort(arr, limit);
    for(int i = 0; i<limit; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}




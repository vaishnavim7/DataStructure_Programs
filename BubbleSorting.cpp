#include<iostream>
#include<stdio.h>
using namespace std;

void BubbleSort(int arr[], int limit)
{
    for(int i = 0; i<limit-1; i++)
    {
        for(int j = 0; j<limit-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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

    cout<<endl<<"The elements of array after bubble sorting:"<<endl;
    BubbleSort(arr, limit);
    for(int i = 0; i<limit; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}



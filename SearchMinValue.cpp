#include<iostream>
#include<stdlib.h>
using namespace std;

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

    int maxVal = arr[0];

    for(int i = 0; i<limit; i++)
    {
        for(int j = 0; j<limit; j++)
        {
            if(arr[j] > maxVal)
            {
                maxVal = arr[j];
            }
        }
    }
    cout<<endl<<"Max Value is : "<<maxVal<<endl;

    cout<<endl<<"The elements of array:"<<endl;
    for(int i = 0; i<limit; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}





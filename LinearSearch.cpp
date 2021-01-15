#include<iostream>
#include<stdio.h>
using namespace std;

void linearSearch(int arr[], int limit, int num)
{
	int temp = -1;
	for(int i = 0; i<limit; i++)
	{
		if(arr[i] == num)
		{
			cout<<"Linear Search Element "<<arr[i]<<" found at position "<<i<<endl;
			temp = 0;
		}
	}
	
	if(temp == -1)
	{
		cout<<"Linear Search Element is Not Found : "<<endl;
	}
}

int main()
{
	int limit;
    int arr[limit];
	int ele;
    cout<<"Enter the size of array:"<<endl;
    cin>>limit;

    cout<<"Enter the elements of array:"<<endl;
    for(int i = 0; i<limit; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter the element to search:"<<endl;
    cin>>ele;
    linearSearch(arr, limit, ele);
    
    return 0;
}

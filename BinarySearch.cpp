#include<iostream>
#include<stdio.h>
using namespace std;

int binarySearch(int arr[], int num, int l, int r)
{
	int mid = (r+l)/2;
	while(l<=r)
	{
		if(arr[mid] == num)
		{
			return mid;
		}
		else if(arr[mid] < num)
		{
			l = mid + 1;
		}
		else if(arr[mid] > num)
		{
			r = mid - 1;
		}
		mid = (r+l)/2;
	}
	return -1;
}

int main()
{
    int arr[5];
	int ele;

    cout<<"Enter the elements of array in sorted order:"<<endl;
    for(int i = 0; i<5; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter the element to search:"<<endl;
    cin>>ele;
    int res = binarySearch(arr, ele, 0, 4);
    
    if(res == -1)
    {
    	cout<<"Not Found"<<endl;
	}
	else{
		cout<<"Match Found at index "<<res<<endl;
	}
    
    return 0;
}

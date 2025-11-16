#include<iostream>
using namespace std;

bool checkheapdown(int arr[],int n)
{
	for (int i = 0; i <= (n-2)/2; i++) 
	{  
        int left = 2*i + 1;
        int right = 2*i + 2;
	
	if(left < n && arr[left] > arr[i])
	{
		return false;
	}
	
		if(right < n && arr[right] > arr[i])
	{
		return false;
	}
}
	return true;

}
void heapdown(int arr[],int n,int i)
{
	int largest=i;
	int left= 2*i + 1;
	int right= 2*i + 2;
	
	if(left < n && arr[left] > arr[largest])
	{
		largest=left;
	}
	
		if(right < n && arr[right] > arr[largest])
	{
		largest= right;
	}
	
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		heapdown(arr,n,largest);
	}
}

void heapsort(int arr[],int n)
{
	for(int i=n/2-1 ; i>=0 ; i--)
	{
		heapdown(arr,n,i);
	}
	
	for(int i=n-1 ; i>=0 ; i--)
	{
		swap(arr[0],arr[i]);
		heapdown(arr,i,0);
	}
}

int main()
{
	int arr[]={8, 7 , 6 ,5 , 4};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	if(checkheapdown(arr,n))
	{
		cout<<"ARRAY IS MAX HEAP"<<endl;
	}
	else
	{
		cout<<"ARRAY IS NOT MAX HEAP"<<endl;
	}
	
	heapsort(arr,n);
	
	cout<<"SORTED ARRAY"<<endl;
	for(int i=0; i<n ; i++)
	{
		cout <<arr[i]<<" ";
	}
	
	return 0;
}
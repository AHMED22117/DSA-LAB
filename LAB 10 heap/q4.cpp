#include<iostream>
using namespace std;

void heapifydown(int arr[],int n,int i)
{
	int largest=i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(left < n && arr[left] > arr[largest])
	{
		largest=left;
	}
	if(right < n && arr[right] > arr[largest])
	{
		largest=right;
	}
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		heapifydown(arr,n,largest);
	}
}

void heapifyup(int arr[],int i)
{
	int parent=(i-1)/2;
	if(i > 0 && arr[i] > arr[parent])
	{
		swap(arr[i],arr[parent]);
		heapifyup(arr,parent);
	}
}

void buildheap(int arr[],int n)
{
	for(int i=n/2-1 ;i> 0 ;i--)
	{
		heapifydown(arr,n,i);
	}
	
 } 
 
 int main()
 {
 	int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
 	int n=sizeof(arr)/sizeof(arr[0]);
 	
 	buildheap(arr,n);
 	
 		cout << "Max Heap: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
 }
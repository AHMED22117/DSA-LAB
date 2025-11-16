#include<iostream>
using namespace std;

void heapifydown(int arr[],int n,int i)
{
    int smallest=i;
    int left=2*i + 1;
    int right= 2*i + 2;
    
    if(left < n && arr[left] < arr[smallest])
        smallest = left;
    
    if(right < n && arr[right] < arr[smallest])
        smallest = right;
    
    if(smallest != i)
    {
        swap(arr[i],arr[smallest]);
        heapifydown(arr,n,smallest);
    }
}

void heapsort(int arr[],int n)
{
    for(int i=n/2-1 ; i>=0; i--)
        heapifydown(arr,n,i);
    
    for(int i=n-1; i>= 0 ;i--)
    {
        swap(arr[0],arr[i]);
        heapifydown(arr,i,0);
    }
}

int main()
{
    int arr1[]={1, 23, 12, 9, 30, 2, 50};
    int arr2[]={12, 3, 5, 7, 19};
    
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    
    heapsort(arr1,size1);
    heapsort(arr2,size2);
    
    int k=3;
    cout << "INPUT: K = 3 "<<endl;
    cout << "OUTPUT: "<< arr1[k-1] << endl;
    
    k=2;
        cout << "INPUT: K = 2 "<<endl;
        cout << "OUTPUT: "<<arr2[k-1] << endl;
    return 0;
}

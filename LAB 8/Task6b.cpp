// Using Merge Sort

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100], R[100];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[10], arr2[10];
    cout << "Enter 10 integers for array 1: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter 10 integers for array 2: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr2[i];
    }

    int combined[20];
    for (int i = 0; i < 10; i++)
    {
        combined[i] = arr1[i];
    }
    for (int i = 0; i < 10; i++)
    {
        combined[10 + i] = arr2[i];
    }

    mergeSort(combined, 0, 19);

    cout << "\nCombined and Sorted Array (Merge Sort):\n";
    printArray(combined, 20);

    return 0;
}

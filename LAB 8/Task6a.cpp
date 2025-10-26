// Using Radix Sort

#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]--;
        output[count[digit]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    int exp = 1;
    while (m / exp > 0)
    {
        countingSort(arr, n, exp);
        exp = exp * 10;
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

    radixSort(combined, 20);

    cout << "\nCombined and Sorted Array (Radix Sort):\n";
    printArray(combined, 20);

    return 0;
}

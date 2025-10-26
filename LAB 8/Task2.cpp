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
    int output[10000];
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

void radixSortAscending(int arr[], int n)
{
    int m = getMax(arr, n);
    int exp = 1;
    while (m / exp > 0)
    {
        countingSort(arr, n, exp);
        exp = exp * 10;
    }
}

void radixSortDescending(int arr[], int n)
{
    radixSortAscending(arr, n);
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
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
    int arr[10];
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ascending[10];
    int descending[10];
    for (int i = 0; i < n; i++)
    {
        ascending[i] = arr[i];
        descending[i] = arr[i];
    }

    radixSortAscending(ascending, n);
    cout << "\nArray Sorted in Ascending Order:\n";
    printArray(ascending, n);

    radixSortDescending(descending, n);
    cout << "\nArray Sorted in Descending Order:\n";
    printArray(descending, n);

    return 0;
}

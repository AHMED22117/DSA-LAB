#include <iostream>
using namespace std;

int comparisons = 0;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int pivotFirst(int low, int high)
{
    return low;
}

int pivotMiddle(int low, int high)
{
    return (low + high) / 2;
}

int pivotRandom(int low, int high)
{
    return low + (rand() % (high - low + 1));
}

int pivotMedian(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    int a = arr[low];
    int b = arr[mid];
    int c = arr[high];
    if ((a > b) != (a > c))
    {
        return low;
    }
    else if ((b > a) != (b > c))
    {
        return mid;
    }
    else
    {
        return high;
    }
}

int partition(int arr[], int low, int high, int pivotIndex)
{
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int method)
{
    if (low < high)
    {
        int pivotIndex;

        if (method == 1)
        {
            pivotIndex = pivotFirst(low, high);
        }
        else if (method == 2)
        {
            pivotIndex = pivotRandom(low, high);
        }
        else if (method == 3)
        {
            pivotIndex = pivotMiddle(low, high);
        }
        else
        {
            pivotIndex = pivotMedian(arr, low, high);
        }

        int pi = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pi - 1, method);
        quickSort(arr, pi + 1, high, method);
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

void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = 7;

    int temp[7];

    cout << "Original Array:\n";
    printArray(arr, n);

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 1);
    cout << "\nSorted using First Element Pivot:\n";
    printArray(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 2);
    cout << "\nSorted using Random Element Pivot:\n";
    printArray(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 3);
    cout << "\nSorted using Middle Element Pivot:\n";
    printArray(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 4);
    cout << "\nSorted using Median-of-Three Pivot:\n";
    printArray(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}

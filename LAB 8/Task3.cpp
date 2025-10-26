#include <iostream>
#include <string>
using namespace std;

struct Runner
{
    string name;
    int time;
};

void merge(Runner arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner *L = new Runner[n1];
    Runner *R = new Runner[n2];

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
        if (L[i].time <= R[j].time)
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

    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void print_topfive(Runner arr[], int n)
{
    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5 && i < n; i++)
    {
        cout << arr[i].name << " - " << arr[i].time << " seconds" << endl;
    }
}

int main()
{
    Runner runners[10];
    int n;

    cout << "Enter number of participants (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of runner " << i + 1 << ": ";
        cin >> runners[i].name;
        cout << "Enter finish time (in seconds): ";
        cin >> runners[i].time;
    }

    mergeSort(runners, 0, n - 1);

    cout << "\nAll Runners Sorted by Finish Time (Ascending):\n";
    for (int i = 0; i < n; i++)
    {
        cout << runners[i].name << " - " << runners[i].time << " seconds" << endl;
    }

    print_topfive(runners, n);

    return 0;
}

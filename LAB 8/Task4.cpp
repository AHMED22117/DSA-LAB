#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    string name;
    float price;
    string description;
    string availability;

    void input()
    {
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter product price: ";
        cin >> price;
        cout << "Enter product description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter availability status (Available/OutOfStock): ";
        cin >> availability;
    }

    void display()
    {
        cout << name << " - $" << price << " - " << description << " - " << availability << endl;
    }
};

void swap(Product &a, Product &b)
{
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high)
{
    float pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j].price < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Product arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n = 3;
    Product products[n];

    cout << "Enter details for 3 products:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i + 1 << ":\n";
        products[i].input();
    }

    quickSort(products, 0, n - 1);

    cout << "\nProducts Sorted by Price (Ascending Order):\n";
    for (int i = 0; i < n; i++)
    {
        products[i].display();
    }

    return 0;
}

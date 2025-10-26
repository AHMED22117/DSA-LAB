#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int score;
    Node *next;
    Node(string n, int s)
    {
        name = n;
        score = s;
        next = nullptr;
    }
};

void addNode(Node **head, string name, int score)
{
    Node *newNode = new Node(name, score);
    newNode->next = *head;
    *head = newNode;
}

int getMax(Node *head)
{
    int max = head->score;
    while (head != nullptr)
    {
        if (head->score > max)
        {
            max = head->score;
        }
        head = head->next;
    }
    return max;
}

Node *countingSort(Node *head, int exp)
{
    Node *output[10000] = {nullptr};
    int count[10] = {0};
    Node *temp = head;

    while (temp != nullptr)
    {
        int digit = (temp->score / exp) % 10;
        count[digit]++;
        temp = temp->next;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    Node *nodes[10000];
    int i = 0;
    temp = head;
    while (temp != nullptr)
    {
        nodes[i] = temp;
        i++;
        temp = temp->next;
    }

    Node *sorted[10000];
    for (int j = i - 1; j >= 0; j--)
    {
        int digit = (nodes[j]->score / exp) % 10;
        count[digit]--;
        sorted[count[digit]] = nodes[j];
    }

    for (int k = 0; k < i - 1; k++)
    {
        sorted[k]->next = sorted[k + 1];
    }

    if (i > 0)
    {
        sorted[i - 1]->next = nullptr;
    }

    return sorted[0];
}

void radixSort(Node **head)
{
    int m = getMax(*head);
    int exp = 1;
    while (m / exp > 0)
    {
        *head = countingSort(*head, exp);
        exp = exp * 10;
    }
}

int countNodes(Node *head)
{
    int c = 0;
    while (head != nullptr)
    {
        c++;
        head = head->next;
    }
    return c;
}

void toArray(Node *head, Node *arr[], int size)
{
    int i = 0;
    while (head != nullptr && i < size)
    {
        arr[i] = head;
        i++;
        head = head->next;
    }
}

int binarySearch(Node *arr[], int size, string name, int score)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid]->name == name && arr[mid]->score == score)
        {
            return mid;
        }
        else if (arr[mid]->score < score)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void deleteNode(Node **head, int pos)
{
    if (*head == nullptr)
    {
        return;
    }

    Node *temp = *head;
    if (pos == 0)
    {
        *head = temp->next;
        delete temp;
        return;
    }

    for (int i = 0; temp != nullptr && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        return;
    }

    Node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int main()
{
    Node *head = nullptr;
    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);

    radixSort(&head);

    cout << "Sorted Student Records:" << endl;
    printList(head);

    int size = countNodes(head);
    Node *arr[10000];
    toArray(head, arr, size);

    string name;
    int score;
    cout << "\nEnter name and score to delete: ";
    cin >> name >> score;

    int pos = binarySearch(arr, size, name, score);
    if (pos != -1)
    {
        deleteNode(&head, pos);
        cout << "\nRecord deleted. Updated List:" << endl;
        printList(head);
    }
    else
    {
        cout << "\nRecord not found. No changes made." << endl;
    }

    return 0;
}

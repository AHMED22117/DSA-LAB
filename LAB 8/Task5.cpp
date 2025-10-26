#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **headRef, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *getTail(Node *curr)
{
    while (curr != nullptr && curr->next != nullptr)
    {
        curr = curr->next;
    }
    return curr;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = nullptr;
    Node *curr = head;
    Node *tail = pivot;

    while (curr != pivot)
    {
        if (curr->data < pivot->data)
        {
            if ((*newHead) == nullptr)
            {
                (*newHead) = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (prev != nullptr)
            {
                prev->next = curr->next;
            }
            Node *temp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if ((*newHead) == nullptr)
    {
        (*newHead) = pivot;
    }

    (*newEnd) = tail;
    return pivot;
}
Node *quickSort(Node *head, Node *end)
{
    if (!head || head == end)
    {
        return head;
    }

    Node *newHead = nullptr;
    Node *newEnd = nullptr;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node *temp = newHead;
        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSort(newHead, temp);

        Node *tail = getTail(newHead);
        tail->next = pivot;
    }

    pivot->next = quickSort(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node **headRef)
{
    (*headRef) = quickSort(*headRef, getTail(*headRef));
}

int main()
{
    Node *head = nullptr;
    push(&head, 3);
    push(&head, 5);
    push(&head, 1);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 10);

    cout << "Original Linked List:\n";
    printList(head);

    quickSort(&head);

    cout << "\nSorted Linked List:\n";
    printList(head);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
};

node *create(vector<int> arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(node *head)
{
    node *mover = head;
    while (mover)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

node *deleteNode(node *head, int n)
{

    if (head == NULL)
        return NULL;
    if (n == 1)
    {
        node *mover = head;
        head = mover->next;
        delete mover;
        return head;
    }
    int cnt = 1;
    node *mover = head, *temp = NULL;
    while (mover != NULL)
    {
        if (cnt == n)
        {
            temp->next = temp->next->next;
            delete mover;
            break;
        }
        temp = mover;
        mover = mover->next;
        cnt++;
    }

    return head;
}

int main()
{
    vector<int> arr = {12, 4, 64, 1};
    node *head = create(arr);
    int n = 5;
    head = deleteNode(head, n);
    print(head);

    return 0;
}

// g++ src/03-DeleteNode.cpp -o dist\03-DeleteNode.exe && dist\03-DeleteNode.exe
// src\03-DeleteNode.cpp
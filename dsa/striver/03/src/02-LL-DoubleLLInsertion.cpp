#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *back;

public:
    node(int data1, node *next1, node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

node *create(vector<int> arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(node *mover)
{
    while (mover)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
}

node *insertB4Head(node *head)
{

    if (head == NULL)
        return NULL;

    node *temp = head;
    node *newNode = new node(1, head, nullptr);
    head->back = newNode;

    return newNode;
}

node *insertB4Tail(node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        return insertB4Head(head);
    }

    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    node *newNode = new node(1, temp, temp->back);
    temp->back->next = newNode;
    temp->back = newNode;

    return head;
}

node *insertB4K(node *head, int k)
{
    int count = 0;
    node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }

    if (count == 1)
    {
        return insertB4Head(head);
    }

    node *prev = temp->back;
    node *newNode = new node(1, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertB4Node(node* Node){
    node* prev = Node->back;
    node* newNode = new node(1, Node, prev);
    prev->next = newNode;
    Node->back = newNode;
}

int main(int argc, char *argv[])
{

    vector<int> arr = {23, 7, 9, 64};
    node *head = create(arr);
    // head = insertB4Head(head);
    // head = insertB4Tail(head);
    // head = insertB4K(head, atoi(argv[1]));
    insertB4Node(head->next->next->next);

    print(head);
    return 0;
}


// g++ src\02-LL-DoubleLLInsertion.cpp -o dist\02-LL-DoubleLLInsertion.exe && dist\02-LL-DoubleLLInsertion.exe
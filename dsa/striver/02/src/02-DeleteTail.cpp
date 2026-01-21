#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

public:
    node(int data1)
    {
        data = data1;
        next = nullptr;
    }

public:
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
        /* code */
    }

    return head;
}

void print(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* deleteTail(node* mover){
    if(mover == NULL || mover->next == NULL) return NULL;
    node* temp = mover;
    while(temp->next->next != NULL){
        temp = temp->next;
        // continue;
    }
    delete temp->next;
    temp->next = nullptr;

    return mover;
};

int main()
{

    vector<int> arr = {5, 12, 8, 7};
    node *head = create(arr);
    head = deleteTail(head);
    print(head);

    return 0;
}

// g++ src/02-DeleteTail.cpp  -o dist\02-DeleteTail.cpp
// src/02-DeleteTail.cpp
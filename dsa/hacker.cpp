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
    node* temp;
    node* head = mover;
    while(mover){
        temp = mover;
        mover = mover->next;
    }

    delete temp;

    return head;
};

int main()
{

    vector<int> arr = {5, 12, 8, 7};
    node *head = create(arr);
    head = deleteTail(head);
    print(head);


    return 0;
}

// g++ src\q.cpp -o dist\q.exe && dist\q.exe
// g++ src\01-LL-DoubleLL.cpp -o dist\01-LL-DoubleLL.exe && dist\01-LL-DoubleLL.exe
// g++ src\02-LL-DoubleLLInsertion.cpp -o dist\02-LL-DoubleLLInsertion.exe && dist\02-LL-DoubleLLInsertion.exe
// src/02-LL-DoubleLLInsertion.cpp
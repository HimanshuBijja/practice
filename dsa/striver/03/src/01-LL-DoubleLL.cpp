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

// node *deleteHead(node *head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;
//     node *mover = head;

//     head = head->next;
//     head->back = nullptr;
//     delete mover;

//     return head;
// }

// node* deleteTail(node* head){
//     if(head == NULL || head->next == NULL) return NULL;

//     node* temp = head;
//     while(temp->next->next != nullptr){
//         temp = temp->next;
//     }

//     node* deleteNode = temp->next;
//     temp->next = nullptr;
//     delete deleteNode;

//     return head;
// }

// node* deleteK(node* head, int k){
//     if(head == NULL){
//         return NULL;
//     }
//     int count = 0;node* temp = head;
//     while(temp){
//         count++;
//         if(count == k) break;
//         temp = temp->next;
//     }
//     if(count < k || k < 1){
//         cout << "Out of bonds";
//         return NULL;
//     }
//     node* front = temp->next;
//     node* prev = temp->back;

//     if(front == NULL && prev == NULL){
//         return NULL;
//     }
//     if(front == NULL){
//         prev->next = nullptr;
//         delete temp;
//         return head;
//     }
//     if(prev == NULL){
//         front->back = nullptr;
//         delete temp;
//         return front;
//     }
//     prev->next = front;
//     front->back = prev;
//     delete temp;
//     return head;
// }

void deleteNode(node* Node){
    node* prev = Node->back;
    node* front = Node->next;


    if(front == NULL){
        prev->next = nullptr;
        Node->back = nullptr;
        delete Node;
        return;
    }

    prev->next = Node->next;
    front->back = Node->back;
    delete Node;



}

int main(int argc, char* argv[])
{

    vector<int> arr = {23, 7, 9, 64};
    node *head = create(arr);

    // head = deleteHead(head);
    // head = deleteTail(head);
    // head  = deleteK(head,  atoi(argv[1]));
    deleteNode(head->next->next->next);

    print(head);
    return 0;
}

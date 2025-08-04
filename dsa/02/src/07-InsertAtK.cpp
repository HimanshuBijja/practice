#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:
    node(int data1, node* next1){
        data = data1;
        next = next1;
    }

    public:
    node(int data1){
        data = data1;
        next = nullptr;
    }
};

node* create(vector<int> arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i=1; i<arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next= temp;
        mover = temp;
    }
    return head;
}

void print(node* mover){
    while(mover){
        cout << mover->data << " ";
        mover = mover->next;
    }
}

node* insertAtK(node* head, int k){
    int count = 0;
    node* mover = head;
    while(mover){
        count++;
        mover = mover->next;
    }

    if(count+1 < k){
        cout << "Invalid position" ;
        return NULL;
    }


    if(head == NULL && k == 1){// check
        return new node(1);
    }
    if(k == 1){
        return new node(1, head);//check
    }
    count = 0; mover = head; node* prev = NULL;
    while(mover){
        count++;
        if(count == k){
            prev->next = new node(9, mover);
            return head;
        }
        prev = mover;
        if(mover->next == nullptr && count+1 == k){
            mover->next = new node(9);
            return head;
        }
        mover = mover->next;
    }


    return NULL;


}

int main(){

    vector <int> arr = {34, 8, 91,3};
    node* head = create(arr);

    head = insertAtK(head, 6);

    print(head);

    return 0;
}

// g++ src\07-InsertAtK.cpp -o dist\07-InsertAtK.exe && dist\07-InsertAtK.exe
// src/07-InsertAtK.cpp
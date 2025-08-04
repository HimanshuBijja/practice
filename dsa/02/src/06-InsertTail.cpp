#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:
    node(int data1){
        data = data1;
        next = nullptr;
    }

    node(int data1, node* next1){
        next = next1;
    }
};

node* create(vector<int> arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i=1; i< arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

node* insertTail(node* head){

    if(head == NULL){
        return new node(1);
    }
    node* mover = head;
    while(mover->next != nullptr){
        mover = mover->next;
    }
    mover->next = new node(9);

    return head;
}

int main(){

    vector <int> arr = { 34,56,32,3};
    node* head = create(arr);
    head = insertTail(head);

    print(head);

    return 0;
}

// g++ src\06-InsertTail.cpp -o dist\06-InsertTail.exe && dist\06-InsertTail.exe
// src/06-InsertTail.cpp
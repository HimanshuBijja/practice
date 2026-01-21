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

node* create(vector <int> arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i=1; i<arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
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


int main(){

    vector <int> arr = {23, 7,9,64};
    node* head = create(arr);

    print(head);
    return 0;
}

// g++ src\05-InsertHead.cpp -o dist\05-InsertHead.exe && dist\05-InsertHead.exe
// src/05-InsertHead.cpp
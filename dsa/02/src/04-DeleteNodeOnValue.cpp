#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node *next;

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
    for(int i =1; i<arr.size(); i++){
        node * temp = new node(arr[i]);
        mover->next = temp;
        mover =temp;
    }

    return head;
}

void print(node* head){
    node* temp = head;
    while(temp){
        cout << temp->data  << " ";
        temp = temp->next;
    }

    // delete temp;
}

node* deleteNodeOnValue(node* head, int val){
    if(head == NULL) return NULL;

    if( head->data == val){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node* temp = head;
    while(temp->next != nullptr){
        node* prev = temp;
        temp = temp->next;
        if(temp->data == val){
            prev->next = prev->next->next;
            delete temp;
            return head;
        }
    }
    cout << "NULL";
    return NULL;


}

int main(){

    vector <int> arr = {23, 4,65, 32};
    node* head = create(arr);
    head =  deleteNodeOnValue(head, 9);
    print(head);
    return 0;
}
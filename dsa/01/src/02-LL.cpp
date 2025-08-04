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

node* convert(vector<int> arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i =0; i< arr.size(); i++){
        node* temp = new node(arr[i]);
        mover ->next = temp;
    }
    return head;
}

int main(){

    vector <int> arr = {3,2,4,23};
    node* head = convert(arr);
    cout << head->data;
}
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;

    node(int data1, node* next1){
        next = next1;
        data = data1;
    }
};

int main(){
    vector <int> arr = {4,213,23};
    node* y = new node(arr[1], nullptr);
    cout << y->data ;

}
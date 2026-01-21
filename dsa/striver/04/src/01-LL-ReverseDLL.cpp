#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node* back;

public:
  node(int data1, node *next1, node* back1)
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


node* reverseDLLwithStack(node* head){ //reversing wiht stack
    node* temp = head;
    stack <int> st;
    while(temp ){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

node* reverseDLL(node* head){
  node* temp = head;node* newHead;
  while(temp){
    node* front = temp->next;
    temp->next = temp->back;
    temp->back = front;
    
    newHead = temp;
    temp = temp->back;
  }

  return newHead ;
}

int main()
{

  vector<int> arr = {23, 7, 9, 64};
  node *head = create(arr);
    // head = reverseDLLwithStack(head);
    head = reverseDLL(head);
  print(head);
  return 0;
}


// g++ src\01-LL-ReverseDLL.cpp -o dist\01-LL-ReverseDLL.exe && dist\01-LL-ReverseDLL.exe
// 04/01-LL-ReverseDLL.cpp
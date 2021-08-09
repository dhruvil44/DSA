//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
  }
};


void insertAtHead(Node* &head, int data) {

  Node* new_node = new Node(data);

  if(head==NULL) {
      head = new_node;
      new_node->next = new_node;
      return;
  }

  Node* tail = head;
  while(tail->next!=head) {
    tail = tail->next;
  }


  tail->next = new_node;
  new_node->next = head;
  head = new_node;
}

void insertAtEnd(Node* &head, int data) {

  Node* new_node = new Node(data);

  if(head==NULL) {
    head = new_node;
    new_node->next = new_node;
    return;
  }

  Node* tail = head;
  while(tail->next!=head) {
    tail = tail->next;
  }

  tail->next = new_node;
  new_node->next = head;
}

void printList(Node* head) {
  Node* temp = head->next;
  cout<<head->data<<" -> ";
  while(temp!=head) {
    cout<<temp->data<<" -> ";
    temp = temp->next;
  }
  cout<<endl;
  cout<<endl;
}

int main() {

  Node* head = NULL;

  insertAtEnd(head,4);
  insertAtEnd(head,5);
  insertAtHead(head,3);
  insertAtHead(head,2);

  printList(head);
  
  return 0;
}

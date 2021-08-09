//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node* prev;

  Node(int data) {
    this->data = data;
  }
};


void insertAtHead(Node* &head, int data) {
    Node* new_node = new Node(data);

    if(head==NULL) {
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        return;
    }


    new_node->next = head;
    new_node->prev = NULL;

    head->prev = new_node;
    head = new_node;
}

void insertAtEnd(Node* &head, int data) {

  Node* new_node = new Node(data);

  if(head==NULL) {
    head = new_node;
    new_node->next = NULL;
    new_node->prev = NULL;
    return;
  }

  Node* temp = head;
  while(temp->next!=NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
  new_node->prev = temp;
  new_node->next = NULL;
}


void insert(Node* &head, int pos, int data) {

  Node* new_node = new Node(data);

  if(head==NULL) {
    head = new_node;
    new_node->next = NULL;
    new_node->prev = NULL;
    return;
  }

  if(pos==1) {
    insertAtHead(head,data);
    return;
  }

  Node* temp = head;
  int c=1;

  while(c!=pos) {
    temp = temp->next;
    c++;
  }



  temp->prev->next = new_node;
  new_node->next = temp;
  new_node->prev = temp->prev;
  temp->prev = new_node;

}


void printList(Node* head) {
  while(head) {
    cout<<head->data<<" -> ";
    head = head->next;
  }
  cout<<endl;
}


int main() {

  Node* head = NULL;

  insertAtHead(head,4);
  insertAtEnd(head,5);
  insertAtEnd(head,6);
  insertAtHead(head,3);

  printList(head);

  return 0;
}

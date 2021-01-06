//Author: Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;


//class for the Node
class Node{

public:
  int data;
  Node *next;

  Node(int x)
  {
    data=x;
    next=NULL;
  }
};


//inserting at the beginning of the LL
void insertAtHead(Node* &head, int x)
{
  Node *n = new Node(x);
  n->next = head;
  head = n;
}

//inserting at the end of the LL
void insertAtEnd(Node* &head, int x)
{
  Node* n = new Node(x);

  Node* temp = head;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }

  temp->next=n;
}


//finding the kth node from the last by RUNNER TECHNIQUE
Node* findTheKthNodeFromLast(Node* head, int k)
{
    Node* slow = head;
    Node* fast = head;

    while(k--)
    {
        fast=fast->next;
    }

    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }

    return slow;
}


//print the LL
void printList(Node* head)
{
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head=head->next;
  }
}


int main(){

  //making the head pointer
  Node *head = NULL;

  insertAtHead(head,1);
  insertAtHead(head,2);
  insertAtEnd(head,100);
  insertAtEnd(head,200);
  insertAtEnd(head,300);
  printList(head);
  cout<<endl;


  Node* k = findTheKthNodeFromLast(head,3);
  cout<<k->data;
  cout<<endl;
  return 0;
}

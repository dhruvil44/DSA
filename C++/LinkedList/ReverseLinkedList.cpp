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


//reversing the LL iterative method
void reverseLL(Node* &head)
{
  Node* prev = NULL;
  Node* curr = head;
  Node* nextNode=NULL;

  while(curr!=NULL)
  {
    nextNode=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nextNode;

  }

  head=prev;
}


//reversing the LL recursively
Node* recursiveReverse(Node* head) {
  if(head==NULL || head->next==NULL) {
    return head;
  }

  Node* new_head = recursiveReverse(head->next);

  head->next->next = head;
  head->next = NULL;

  return new_head;
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
  printList(head);
  cout<<endl;

  reverseLL(head);
  printList(head);
  cout<<endl;

  Node* rev_head = recursiveReverse(head);
  printList(rev_head);
  cout<<endl;



  return 0;
}

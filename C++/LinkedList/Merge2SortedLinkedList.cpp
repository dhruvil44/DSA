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


//merging 2 sorted LL recursively similar to merge sort
Node* mergeLL(Node* head1, Node* head2){

  if(head1==NULL)
  {
    return head2;
  }

  else if(head2==NULL)
  {
    return head1;
  }

  Node* head;

  if(head1->data < head2->data)
  {
    head = head1;
    head1 = head1->next;
    head->next = mergeLL(head1,head2);
  }

  else{
    head = head2;
    head2 = head2->next;
    head->next = mergeLL(head1,head2);
  }

  return head;

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
  Node *head1 = NULL;
  Node *head2 = NULL;

  insertAtHead(head1,1);
  insertAtEnd(head1,2);
  insertAtEnd(head1,100);
  insertAtEnd(head1,200);
  insertAtEnd(head1,300);
  printList(head1);
  cout<<endl;

  insertAtHead(head2,3);
  insertAtEnd(head2,4);
  insertAtEnd(head2,10);
  insertAtEnd(head2,20);
  insertAtEnd(head2,3000);
  printList(head2);
  cout<<endl;


  Node *head = mergeLL(head1,head2);
  printList(head);
  cout<<endl;

  cout<<endl;
  return 0;
}

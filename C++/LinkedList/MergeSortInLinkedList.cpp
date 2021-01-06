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


//finding the MidPoint of the LL
Node* findMidPoint(Node* head)
{
  Node* slow = head;
  Node* fast = head->next;

  while(fast!=NULL && fast->next!=NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }

  return slow;
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


Node*  mergeSort(Node* head)
{
  if(head==NULL || head->next==NULL)
  {
    return head;
  }

  Node* midPoint = findMidPoint(head);

  Node* a = head;
  Node* b = midPoint->next;
  midPoint->next=NULL;

  a = mergeSort(a);
  b = mergeSort(b);

  Node* c = mergeLL(a,b);
  return c;
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
  insertAtEnd(head,200);
  insertAtEnd(head,100);
  insertAtEnd(head,2);
  insertAtEnd(head,300);
  printList(head);
  cout<<endl;



  Node* c = mergeSort(head);
  printList(c);
  cout<<endl;


  return 0;
}

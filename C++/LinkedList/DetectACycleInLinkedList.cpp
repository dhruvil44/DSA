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


//Runner technique to detect cycle
bool detectCycle(Node* head)
{
  Node* slow = head;
  Node* fast = head;

  while(fast!=NULL && fast->next!=NULL)
  {
    fast = fast->next->next;
    slow = slow->next;

    if(fast==slow)
    {
      return true;
    }
  }

  return false;
}

//Floyd's Algo for removing cycle in LL
void removeCycle(Node* &head)
{
  Node* slow = head;
  Node* fast = head;
  Node* prev;
  if(detectCycle(head))
  {

    while(slow!=fast)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow = head;

    while(fast!=slow)
    {
      slow=slow->next;
      prev=fast;
      fast=fast->next;
    }

    prev->next=NULL;

  }



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
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = head->next;


  //1-> 2-> 3-> 4-> 5
//      ^-> -> -> ->^

  cout<<detectCycle(head)<<endl;

  removeCycle(head);
  cout<<endl;
  printList(head);


  return 0;
}

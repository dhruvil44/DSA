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


//returns the lenght of the LL
int lengthOfLL(Node* head)
{
  int t=0;
  while(head!=NULL)
  {
    t++;
    head=head->next;
  }
  return t;
}

//inserting at particular position in the LL starting index=1
void insertAtPosition(Node* &head, int x, int pos)
{
    if(pos==1)
    {
      insertAtHead(head,x);
    }

    else if(pos==lengthOfLL(head)+1)
    {
      insertAtEnd(head,x);
    }

    else{
      int t=1;
      Node* temp = head;
      while(t<pos-1)
      {
        t++;
        temp=temp->next;
      }

      Node* n = new Node(x);
      n->next=temp->next;
      temp->next=n;
    }
}



//delete the start node
void deleteAtHead(Node* &head)
{
  if(head==NULL)
  {
    return;
  }

  Node* temp = head;
  head = temp->next;
  delete(temp);
  return;
}


//delete the end node
void deleteAtEnd(Node* &head)
{
  if(head==NULL)
  {
    return;
  }

  Node* temp = head;
  Node* prev=NULL;

  while(temp->next != NULL)
  {
    prev=temp;
    temp=temp->next;
  }

  prev->next=NULL;
  delete(temp);
  return;

}

//delete node at a given position
void deleteAtPosition(Node* &head, int pos)
{

  if(pos==1)
  {
    deleteAtHead(head);
    return;
  }

  if(pos==lengthOfLL(head))
  {
    deleteAtEnd(head);
    return;
  }

  int t=1;
  Node* temp = head;
  while(t!=pos-1)
  {
    t++;
    temp=temp->next;
  }

  Node* n = temp->next;
  temp->next = temp->next->next;


  delete(n);

  return;


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




int main()
{
  //making the head pointer
  Node *head = NULL;

  insertAtHead(head,1);
  insertAtHead(head,2);
  printList(head);
  cout<<endl;

  insertAtEnd(head,100);
  insertAtEnd(head,200);
  printList(head);
  cout<<endl;

  insertAtPosition(head,1234,1);
  insertAtPosition(head,12345,2);
  insertAtPosition(head,10000,6);
  printList(head);
  cout<<endl;


  deleteAtPosition(head,6);
  deleteAtPosition(head,2);
  printList(head);
  cout<<endl;
  return 0;
}

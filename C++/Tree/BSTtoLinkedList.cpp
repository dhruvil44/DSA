//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


/*
Given a BST.
Convert it to a sorted linked list (Flatten Tree).
Note that we need to manipulate the tree itself to convert it to linked list.
*/

struct node {

  int data;
  struct node *left;
  struct node *right;

};


struct node * create(int x)
{

  struct node * newnode = new struct node;
  newnode->data = x;
  newnode->left=NULL;
  newnode->right=NULL;

  return newnode;
}

class Pair{
public:
  struct node* head;
  struct node* tail;
};

/*
Approach (Post Order Traversal):-

First of all convert the left_subtree to a linked list and right_subtree to a linked list.
Now a root will get a linked list from the left subtree and a linked list from the right_subtree.
Now we just need to connect the root to the tail of the left linked list and to the head of
the right linked list.
*/


Pair convert_binary_tree_to_LL(struct node* root) {

  Pair p;
  if(!root) {
    p.head = NULL;
    p.tail = NULL;
    return p;
  }

  Pair left_LL = convert_binary_tree_to_LL(root->left);
  Pair right_LL = convert_binary_tree_to_LL(root->right);

  if(left_LL.head!=NULL && right_LL.head!=NULL) {
    left_LL.tail->right = root;
    root->right = right_LL.head;

    p.head = left_LL.head;
    p.tail = right_LL.tail;

  }

  if(left_LL.head!=NULL && right_LL.head==NULL) {
    left_LL.tail->right = root;
    root->right = NULL;

    p.head = left_LL.head;
    p.tail = root;
  }

  if(right_LL.head!=NULL && left_LL.head==NULL) {
    root->right = right_LL.head;

    p.head = root;
    p.tail = right_LL.tail;
  }

  if(left_LL.head==NULL && right_LL.head==NULL) {
    p.head = root;
    p.tail = root;
    root->right = NULL;

  }

  return p;
}


int main() {

  struct node * root;
  root = create(10);

  root->left = create(4);
  root->right = create(20);
  root->left->left=create(1);
  root->left->right=create(9);
  root->right->left=create(15);
  root->right->right=create(27);

  Pair LL = convert_binary_tree_to_LL(root);

  while(LL.head!=LL.tail) {
    cout<<LL.head->data<<" ";
    LL.head = LL.head->right;
  }

  cout<<LL.head->data<<endl;

  return 0;
}
